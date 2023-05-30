#!/usr/bin/python3

import sys


from math import sqrt


def factors(filename):
    with open(filename, 'r') as f:
        for line in f:
            n = int(line)
            for i in range(2, int(sqrt(n))+1):
                if n % i == 0:
                    print(f"{n}={i}*{n//i}")
                    break


if __name__ == "__main__":
    factors(sys.argv[1])
