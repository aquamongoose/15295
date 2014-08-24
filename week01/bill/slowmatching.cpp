#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i=0; i+b.size()<=a.size(); i++) {
		bool good = true;
		for (int j=0; j<b.size(); j++) {
			if (a[i+j] != b[j])
				good = false;
		}
		ans += good;
	}
	cout << ans << '\n';
	return 0;
}
