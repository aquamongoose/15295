#!/usr/bin/env python3
from random import randint
from sys import argv
from collections import deque
assert len(argv) == 4
infile = open(argv[1] + '.in', 'w')
outfile = open(argv[1] + '.out', 'w')

n, m = int(argv[2]), int(argv[3])
infile.write('{} {}\n'.format(n, m))
done = set()
adj = [[] for i in range(n)]
for edge in range(m):
    a = randint(1, n)
    b = randint(1, n)
    while (min(a, b), max(a, b)) in done:
        a = randint(1, n)
        b = randint(1, n)
    if a > b:
        a, b = b, a
    done.add((a, b))
    infile.write('{} {}\n'.format(a, b))
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

D = [-1 for i in range(n)]
Q = deque()
Q.append(0)
D[0] = 1
while len(Q) > 0:
    at = Q.popleft()
    for to in adj[at]:
        if D[to] == -1:
            Q.append(to)
            D[to] = D[at]+1

outfile.write('{}\n'.format(D[n-1]))
