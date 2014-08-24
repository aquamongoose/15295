#include <bits/stdc++.h>

using namespace std;

string a, b;
unsigned long long X = 37;

unsigned long long pow (unsigned long long a, unsigned long long b) {
  if (b == 0) return 1;
  unsigned long long x = pow (a, b / 2);
  x *= x;
  if (b % 2 == 1) x *= a;
  return x;
}

int main() {
  cin >> a >> b;
  int n = (int) a.size(), m = (int) b.size(), ans = 0;
  unsigned long long bhash = 0, ahash = 0;
  for (int i = 0; i < m; i++) {
    bhash *= X;
    bhash += (unsigned long long) b[i];
  }
  for (int i = 0; i < m - 1; i++) {
    ahash *= X;
    ahash += (unsigned long long) a[i];
  }
  for (int i = m - 1; i < n; i++) {
    ahash *= X;
    ahash += a[i];
    if (ahash == bhash) ans++;
    ahash -= ((unsigned long long) a[i - m + 1]) * pow ((unsigned long long) X, (unsigned long long) (m-1));
  }
  cout << ans << "\n";
}
