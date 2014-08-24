#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long ll;
const int P = 3, Q = 5, MP = 1000000007, MQ = 1000000009;
const int MAXN = 1000010;
vector<ll> PP, QP;
void init() {
	PP.push_back(1);
	for (int i=1; i<MAXN; i++) {
		PP.push_back(PP.back()*P % MP);
	}
	QP.push_back(1);
	for (int i=1; i<MAXN; i++) {
		QP.push_back(QP.back()*Q % MQ);
	}
}

ll mod(ll a, int m) {
	return ((a%m)+m)%m;
}

int ways(const string& a, const string& b) {
	vector<pair<ll, ll> > ha(a.size()+1);
	pair<ll, ll> hb;
	for (int i=1; i<=a.size(); i++) {
		ha[i] = make_pair((ha[i-1].A*P + a[i-1]) % MP, (ha[i-1].B*Q + a[i-1]) % MQ);
	}
	for (int i=1; i<=b.size(); i++) {
		hb = make_pair((hb.A*P + b[i-1]) % MP, (hb.B*Q + b[i-1]) % MQ);
	}
	int ans = 0;
	for (int i=0; i+b.size()<=a.size(); i++) {
		if (hb == make_pair(mod(ha[i+b.size()].A - PP[b.size()]*ha[i].A, MP),
		                  	mod(ha[i+b.size()].B - QP[b.size()]*ha[i].B, MQ)))
			ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	string a, b;
	cin >> a >> b;
	cout << ways(a, b) << '\n';
	return 0;
}
