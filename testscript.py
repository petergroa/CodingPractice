#!/bin/python3
"""
sdf

TODO:
    - finish execute_test_interactive
    - auto compilation?
"""
import argparse
import builtins
import json
import os
import sys
import unittest
import yaml

from subprocess import run

ACCEPTED_FORMATS = ["json", "yaml"]

class bcolors:
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'

# TODO type args
def execute_test(script_path: str, test: dict) -> str:
    """ Execute commands with arguments directly """
    match type(test["input"]):
        case builtins.str:
            inpt = test["input"].split(' ')
        case builtins.list:
            inpt = [str(args) for args in test["input"]]
        case _:
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

def execute_test_interactive(script_path: str, test: dict) -> str:
    """
    Execute commands by first running script and then sending test to stdin.
    This will try it for a default of 3 minutes. The subprocess will be killed
    if it exceeds the time.
    """
    match type(test["input"]):
        case builtins.str:
            inpt = args.split(' ')
        case builtins.list:
            inpt = [str(args) for args in test["input"]]
        case _:
            inpt = []

    process = run([script_path], capture_output=True)
    

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

    parser.add_argument("script_path", type = str,
        help = ""
    )
    parser.add_argument("test_file_path", type = str,
        help = ""
    )

    parser.add_argument("--interactive", action=argparse.BooleanOptionalAction)
    parser.add_argument("--wait_time", type = int, default = 180,
        help = ""
    )

    main(parser.parse_args())
