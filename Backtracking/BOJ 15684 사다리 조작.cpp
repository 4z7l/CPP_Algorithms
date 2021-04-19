#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, h, res = 100;
//sadari[i][j] : i번째 행, j번째 열에 가로줄 있으면 true (j번째 세로줄과 j+1번째 세로줄 연결)
bool sadari[31][11] = { false, };

bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (sadari[j][start]) start++;
			else if (start>0 && sadari[j][start-1]) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void build_garo(int level, int garo) {
	if (level > 3) return;
	if (check()) {
		res = min(res, level);
		return;
	}
	for (int i = garo; i <= h; i++) {
		for (int j = 1; j <= n-1; j++) {
			if (!sadari[i][j - 1] && !sadari[i][j] && !sadari[i][j + 1]) {
				sadari[i][j] = true;
				build_garo(level + 1, i);
				sadari[i][j] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		sadari[a][b] = true;
	}

	build_garo(0, 1);

	if (res != 100) cout << res;
	else cout << -1;

	return 0;
}