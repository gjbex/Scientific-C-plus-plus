#!/usr/bin/env python

from argparse import ArgumentParser
import random
import sys

def main():
    arg_parser = ArgumentParser(description='generate random data')
    arg_parser.add_argument('n', type=int, help='number of values')
    options = arg_parser.parse_args()
    for _ in range(options.n):
        print(2.0*(0.5 - random.random()))
    return 0


if __name__ == '__main__':
    sys.exit(main())
