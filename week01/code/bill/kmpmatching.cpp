#include <bits/stdc++.h>
using namespace std;

int ways(const string& a, const string& b) {
	vector<int> F(b.size()+1);
	for (int i=2; i<=b.size(); i++) {
		int at = i-1;
		while (at > 0 && b[i-1] != b[F[at]])
			at = F[at];
		if (at > 0) F[i] = F[at]+1;
	}
	int at = 0, ans = 0;
	for (int i=0; i<a.size(); i++) {
		while (at > 0 && a[i] != b[at]) {
			at = F[at];
		}
		if (a[i] == b[at])
			at++;

		if (at == b.size()) {
			ans++;
			at = F[at];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	cout << ways(a, b) << '\n';
	return 0;
}
