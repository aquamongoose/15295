#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  int n = (int) a.size(), m = (int) b.size(), ans = 0;
  for (int i = 0; i < n - m + 1; i++) {
    bool ok = true;
    for (int j = 0; j < m; j++) {
      if (a[i + j] != b[j]) {
        ok = false;
        break;
      }
    }
    ans += ok;
  }
  cout << ans << "\n";
}
