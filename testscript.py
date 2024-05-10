#!/bin/python3
"""
sdf
"""
import argparse
import json
import os
import sys
import unittest

from subprocess import run

def execute_test(script_path: str, test: dict) -> str:
    process = run([script_path, *test["input"].split(' ')], capture_output=True)

    # Command failed
    if process.returncode != 0:
        return process.stderr 

    elif process.stdout[:-1] == test["output"].encode("utf8"):
        print('.', end='')
        return ''

    else:
        print('x', end='')
        return process.stdout

def print_failed(tests: list[tuple]):
    print()
    for test_case in tests:
        print('-'*80)
        print("Input:\n", test_case[0]["input"],
                "\nExpected output:\n", test_case[0]["output"],
                "\nActual output:\n", test_case[1].decode("utf8"),
                end='')
        print('-'*80, end="\n\n")

def main(args):
    if not os.path.isfile(args.script_path):
        printf(f"{args.script_path} is not a file!", file=sys.stderr)
        exit(1)
    elif not os.access(args.script_path, os.X_OK):
        printf(f"{args.script_path} is not a executable!", file=sys.stderr)
        exit(2)

    if not os.path.isfile(args.test_file_path):
        printf(f"{args.test_file_path} is not a file!", file=sys.stderr)
        exit(3)
    elif not args.test_file_path.endswith(".json"):
        printf(f"{args.test_file_path} is not a json file!", file=sys.stderr)
        exit(4)

    failed_tests = list()

    with open(args.test_file_path) as test_file:
        test_json = json.load(test_file)
        for test_case in test_json:
            if result := execute_test(args.script_path, test_case):
                failed_tests.append((test_case, result))

    print_failed(failed_tests)

if __name__ == "__main__":
    parser = argparse.ArgumentParser (
            prog = "TestACM",
            description = "Tests a script against a multiple test cases defined in a yaml format"
    )

    parser.add_argument("script_path",
        type = str,
        help = ""
    )
    parser.add_argument("test_file_path",
        type = str,
        help = ""
    )

    main(parser.parse_args())
