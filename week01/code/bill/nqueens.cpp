#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int W, H, N;
vector<string> board;

int solve(int row, int n) {
	if (row == H) return (n == 0);
	int ans = 0;
	if (n > 0)
		for (int i=0; i<W; i++) {
			bool good = true;
			for (int j=row-1; j>=0; j--) {
				if (board[j][i] == 'Q' ||
				   (i >= (row-j) && board[j][i-(row-j)] == 'Q') ||
				   (i+(row-j) < W && board[j][i+(row-j)] == 'Q'))
					good = false;
			}
			if (good) {
				board[row][i] = 'Q';
				ans += solve(row+1, n-1);
				board[row][i] = '.';
			}
		}
	ans += solve(row+1, n);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> W >> H >> N;
	string row;
	for (int i=0; i<W; i++)
		row += '.';
	for (int i=0; i<H; i++) {
		board.push_back(row);
	}
	cout << solve(0, N) << '\n';
	return 0;
}
