#!/usr/bin/env python3
from random import randint
from sys import argv
from collections import deque
assert len(argv) == 2
infile = open(argv[1] + '.in', 'w')
outfile = open(argv[1] + '.out', 'w')

n, m = 10**6, 10**6-1
infile.write('{} {}\n'.format(n, m))
for i in range(m):
    infile.write('{} {}\n'.format(i+1, i+2))
outfile.write('{}\n'.format(n))
