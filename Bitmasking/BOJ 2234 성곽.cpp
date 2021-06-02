#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

short board[50][50];
bool visit[50][50] = {false,};

int room_size[2501];
int room_numbering[50][50];

short dx[4] = {0,-1,0,1};
short dy[4] = {-1,0,1,0};

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int num_of_room = 0;
	int max_area = 0;
	int max_broken_wall_area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				int area = 0;

				num_of_room++;
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				visit[i][j] = true;
				room_numbering[i][j] = num_of_room;

				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					area++;

					for (int d = 0; d < 4; d++) {
						short b = 1 << d;
						if (!(board[x][y] & b)) {
							int nx = x + dx[d];
							int ny = y + dy[d];
							if (!visit[nx][ny]) {
								Q.push({ nx,ny });
								visit[nx][ny] = true;
								room_numbering[nx][ny] = num_of_room;
							}
						}
					}
				}
				max_area = max(max_area, area);
				room_size[num_of_room] = area;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int d = 0; d < 4; d++) {
				short b = 1 << d;
				if (board[i][j] & b) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
					if (room_numbering[i][j] != room_numbering[nx][ny]) {
						int sum = room_size[room_numbering[i][j]] + room_size[room_numbering[nx][ny]];
						max_broken_wall_area = max(max_broken_wall_area, sum);
					}
				}
			}

		}
	}

	cout << num_of_room << '\n';
	cout << max_area << '\n';
	cout << max_broken_wall_area << '\n';

	return 0;
}