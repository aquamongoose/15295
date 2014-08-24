#include <bits/stdc++.h>

using namespace std;

string a, b;
int state[1000000][26];

int main() {
  cin >> a >> b;
  int n = (int) a.size(), m = (int) b.size(), ans = 0;
  int X = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 26; j++) {
      state[i][j] = state[X][j];
    }
    state[i][b[i] - 'a'] = i + 1;
    X = state[X][b[i] - 'a'];
    if (i == 0) X = 0;
  }
  int at = 0;
  for (int i = 0; i < n; i++) {
    at = state[at][a[i] - 'a'];
    if (at == m) {
      ans++;
      at = X;
    }
  }
  cout << ans << "\n";
}
