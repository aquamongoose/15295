#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
int N, M;
vector<int> adj[MAXN];
int D[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(D, -1, sizeof(D));
	queue<int> Q;
	Q.push(0);
	D[0] = 1;
	while (Q.size()) {
		int at = Q.front();
		Q.pop();

		for (int i=0; i<adj[at].size(); i++) {
			if (D[adj[at][i]] == -1) {
				Q.push(adj[at][i]);
				D[adj[at][i]] = D[at]+1;
			}
		}
	}
	cout << D[N-1] << '\n';
	return 0;
}
