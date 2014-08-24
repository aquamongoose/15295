#include <bits/stdc++.h>

using namespace std;

int w, h, n;
int moo[100][100];

bool check() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = i + 1; k < h; k++) {
        for (int l = 0; l < w; l++) {
          if (moo[i][j] == 0 || moo[k][l] == 0) continue;
          if (i == k) return false;
          if (j == l) return false;
          if (k - i == l - j) return false;
          if (k - i == j - l) return false;
        }
      }
    }
  }
  return true;
}

int dfs (int at, int left) {
  if (left == 0) return 1;
  if (at >= h) return 0;
  int tot = 0;
  for (int i = 0; i < w; i++) {
    moo[at][i] = 1;
    if (check()) tot+= dfs (at + 1, left - 1);
    moo[at][i] = 0;
  }
  tot += dfs(at + 1, left);
  return tot;
}

int main() {
  scanf ("%d %d %d", &w, &h, &n);
  printf ("%d\n", dfs(0, n));
}
