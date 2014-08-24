#!/usr/bin/env python3
from random import randint, choice
from sys import argv
alphabet = 'abcdefghijklmnopqrstuvwxyv'
assert len(argv) == 3
infile = open(argv[1] + '.in', 'w')
outfile = open(argv[1] + '.out', 'w')
plen = int(argv[2])
pattern = ''.join(choice(alphabet) for i in range(plen))
text = ''
while len(text)+plen < 1000:
    r = randint(0, 2)
    if r == 0:
        text += pattern
    elif r == 1:
        rind = randint(0, plen-1)
        npat = pattern[:rind] + choice(alphabet) + pattern[rind+1:]
        text += npat
    else:
        rlen = randint(1, plen)
        text += ''.join(choice(alphabet) for i in range(rlen))
infile.write('{}\n{}\n'.format(text, pattern))
