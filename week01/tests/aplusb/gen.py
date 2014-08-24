#!/usr/bin/env python3
from random import randint
from sys import argv
assert len(argv) == 2
a, b = randint(-2 * 10**9, 2 * 10**9), randint(-2 * 10**9, 2 * 10**9)
open(argv[1] + '.in', 'w').write('{} {}\n'.format(a, b))
open(argv[1] + '.out', 'w').write('{}\n'.format(a+b))
