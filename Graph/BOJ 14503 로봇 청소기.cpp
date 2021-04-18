#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

constexpr auto WALL = 1;
constexpr auto NOT_CLEANED = 0;
constexpr auto CLEANED = 2;

int map[51][51];

// 북 동 남 서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m,r,c,d;
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//BFS
	int x = r, y = c, nx, ny, dir=d;
	queue<pair<int, int> > Q;

	// 1. 현재 위치를 청소한다.
	Q.push({ x,y });
	map[x][y] = CLEANED;
	int cnt = 1;

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {

			// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
			dir = (dir + 3) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];

			if (nx<0 || nx>n - 1 || ny < 0 || ny > m - 1) continue;

			if (map[nx][ny] == NOT_CLEANED) {
				// 2-a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 
				//		그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
				Q.push({ nx,ny });
				map[nx][ny] = CLEANED;
				cnt++;
				break;
			}
			else {
				// 2-b. 왼쪽 방향에 청소할 공간이 없다면, 
				//		그 방향으로 회전하고 2번으로 돌아간다.
				if (i == 3) {
					// 2-c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 
					//		바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
					nx = x - dx[dir];
					ny = y - dy[dir];
					// 2-d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 
					//		뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
					if (map[nx][ny] != WALL) {
						Q.push({ nx,ny });
					}
				}
			}
		}
	}

	cout << cnt;

	return 0;
}