#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

// 4:48PM ~ 5:30PM

struct pos { int x, y, cnt, dist; };

int n, m, k;
string board[1000];
bool visit[1000][1000][11] = {false,};

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<pos> Q;
	Q.push({ 0,0,0,1 });
	visit[0][0][0] = true;

	int x, y, cnt, dist, nx, ny;
	int res = 2'147'000'000;
	while (!Q.empty()) {
		x = Q.front().x;
		y = Q.front().y;
		cnt = Q.front().cnt;
		dist = Q.front().dist;
		Q.pop();

		//cout << x << ',' << y << ' ' <<cnt<<' '<< dist[x][y][cnt]<<'\n';

		if (x == n - 1 && y == m - 1) {
			res = min(res, dist);
		}

		for (int d = 0; d < 4; d++) {
			nx = x + dx[d];
			ny = y + dy[d];

			if (nx<0 || nx>n-1 || ny<0 || ny>m-1) continue;
			if (board[nx][ny] == '0') {
				if (!visit[nx][ny][cnt]) {
					Q.push({ nx,ny,cnt,dist+1 });
					visit[nx][ny][cnt] = true;
				}
			}
			else {
				if (cnt<k && !visit[nx][ny][cnt + 1] ) {
					Q.push({ nx,ny,cnt + 1, dist+1 });
					visit[nx][ny][cnt + 1] = true;
				}
			}
		}

	}

	if (res == 2'147'000'000) cout << -1;
	else cout << res;

	return 0;
}