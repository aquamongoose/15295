#include <bits/stdc++.h>

using namespace std;

string a, b;
long long X = 24523454523451LL;

long long pow (long long a, long long b) {
  if (b == 0) return 1;
  long long x = pow (a, b / 2);
  x *= x;
  if (b % 2 == 0) x *= a;
  return x;
}

int main() {
  cin >> a >> b;
  int n = (int) a.size(), m = (int) b.size(), ans = 0;
  long long bhash = 0, ahash = 0;
  for (int i = 0; i < m; i++) {
    bhash *= X;
    bhash += (long long) b[i];
  }
  for (int i = 0; i < m - 1; i++) {
    ahash *= X;
    ahash += (long long) a[i];
  }
  cout << bhash << endl;
  for (int i = m - 1; i < n; i++) {
    ahash *= X;
    ahash += a[i];
	cout << ahash << endl;
    if (ahash == bhash) ans++;
    ahash -= (long long) a[i - m + 1] * pow (X, m-1);
  }
  cout << ans << "\n";
}
