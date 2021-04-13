#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string puyo[12];
bool visit[12][6];
vector<pair<int, int> > same;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void dfs(int x, int y, char ch) {
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx>11 || ny < 0 || ny>5) continue;
		if (!visit[nx][ny] && puyo[nx][ny] == ch) {
			visit[nx][ny] = true;
			same.push_back({ nx,ny });
			dfs(nx, ny, ch);
		}
	}
}

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visit[i][j] = false;
		}
	}
}

bool bomb() {
	bool isPuyoBomb = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visit[i][j] && puyo[i][j] != '.') {
				same.push_back({ i,j });
				visit[i][j] = true;
				dfs(i, j, puyo[i][j]);

				if (same.size() >= 4) {
					isPuyoBomb = true;
					for (pair<int, int> s : same) {
						puyo[s.first][s.second] = '.';
					}
				}
				same.clear();
			}
		}
	}
	return isPuyoBomb;
}

void drop() {
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j > 0; j--) {
			if (puyo[j][i] == '.') {
				int k = j - 1;
				while (k > 0 && puyo[k][i] == '.') k--;
				if (j != k) {
					puyo[j][i] = puyo[k][i];
					puyo[k][i] = '.';
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	// 0. 입력
	for (int i = 0; i < 12; i++) {
		cin >> puyo[i];
	}

	// 1. 공찾기 -> BFS
	// 2. 4개 이상이면 터뜨리기 -> BFS
	// 3. 떨어뜨리기 -> 반복문

	int cnt = 0;
	while (true) {
		init();
		if (bomb()) {
			drop();
			cnt++;
		}
		else break;
	}

	cout << cnt;

	return 0;
}
