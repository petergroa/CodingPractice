#!/bin/python3
"""
sdf
"""
import argparse
import json
import os
import sys
import unittest
import yaml

from subprocess import run

ACCEPTED_FORMATS = ["json", "yaml"]

def execute_test(script_path: str, test: dict) -> str:
    if test["input"]:
        inpt = test["input"].split(' ')
    else:
        inpt = []

    process = run([script_path, *inpt], capture_output=True)

    # Command failed
    if process.returncode != 0:
        return process.stderr 

    elif test["output"] is None and process.stdout.decode("utf8") == '\n':
        return ''

    elif process.stdout.decode("utf8")[:-1] == test["output"]:
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
        print(f"{args.script_path} is not a file!", file=sys.stderr)
        exit(1)
    elif not os.access(args.script_path, os.X_OK):
        print(f"{args.script_path} is not a executable!", file=sys.stderr)
        exit(2)

    testcase_format = args.test_file_path.split('.')[-1]
    if not os.path.isfile(args.test_file_path):
        print(f"{args.test_file_path} is not a file!", file=sys.stderr)
        exit(3)
    elif testcase_format not in ACCEPTED_FORMATS:
        print(f"{args.test_file_path} is not in an accepted format! (", *ACCEPTED_FORMATS, ')', file=sys.stderr)
        exit(4)

    failed_tests = list()

    with open(args.test_file_path) as test_file:
        match testcase_format:
            case "json":
                tests = json.load(test_file)
            case "yaml":
                tests = yaml.safe_load(test_file)
            case _:
                print(f"Oops, not implemented for format {testcase_format}",
                    file=sys.stderr)
                exit(5)
        for test_case in tests:
            if result := execute_test(args.script_path, test_case):
                failed_tests.append((test_case, result))

    print_failed(failed_tests)

if __name__ == "__main__":
    parser = argparse.ArgumentParser (
            prog = "TestScript",
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
