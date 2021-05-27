#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
string board[10000];
bool visit[10000][500] = { false, };
int res = 0;
bool flag = false;

void dfs(int r, int c) {
	if (c == C - 1) {
		res++;
		flag = true;
		return;
	}
	if (flag) return;
	for (int nr : {r - 1, r, r + 1}) {
		if (nr<0 || nr>R - 1 || c+1>C-1 || flag) continue;
		if (board[nr][c + 1] == '.' && !visit[nr][c + 1]) {
			visit[nr][c + 1] = true;
			dfs(nr, c + 1);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < R; i++) {
		flag = false;
		dfs(i, 0);
	}

	cout << res;

	return 0;
}