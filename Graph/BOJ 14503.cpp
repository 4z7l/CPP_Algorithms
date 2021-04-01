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

// �� �� �� ��
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

	// 1. ���� ��ġ�� û���Ѵ�.
	Q.push({ x,y });
	map[x][y] = CLEANED;
	int cnt = 1;

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {

			// 2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
			dir = (dir + 3) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];

			if (nx<0 || nx>n - 1 || ny < 0 || ny > m - 1) continue;

			if (map[nx][ny] == NOT_CLEANED) {
				// 2-a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, 
				//		�� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
				Q.push({ nx,ny });
				map[nx][ny] = CLEANED;
				cnt++;
				break;
			}
			else {
				// 2-b. ���� ���⿡ û���� ������ ���ٸ�, 
				//		�� �������� ȸ���ϰ� 2������ ���ư���.
				if (i == 3) {
					// 2-c. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, 
					//		�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
					nx = x - dx[dir];
					ny = y - dy[dir];
					// 2-d. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, 
					//		���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
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