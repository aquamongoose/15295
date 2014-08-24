#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> out[2000000];
int dist[2000000];

int bfs (int s, int t) {
  int at = 1;
  vector <int> cur, cpy;
  cur.push_back(s);

  while (!cur.empty()) {
    for (int i = 0; i < (int) cur.size(); i++) {
      if (cur[i] == t) return at;
      if (dist[cur[i]] != 0) continue;
      dist[cur[i]] = at;
      for (int j = 0; j < (int) out[cur[i]].size(); j++) {
        cpy.push_back(out[cur[i]][j]);
      }
    }
    cur = cpy;
    cpy.clear();
    at++;
  }
  return -1;
}

int main() {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf ("%d %d", &a, &b);
    out[a].push_back(b);
    out[b].push_back(a);
  }
  printf ("%d\n", bfs (1, n));
}
