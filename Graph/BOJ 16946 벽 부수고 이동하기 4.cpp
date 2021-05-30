#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int groupId=1;
int board[1000][1000];
int visit[1000][1000] = {0,};

int group[1'000'001] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	//cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && visit[i][j] == 0) {
				int cnt = 0;
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				visit[i][j] = groupId;

				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					cnt++;

					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1 || visit[nx][ny] || board[nx][ny]) continue;
						Q.push({ nx,ny });
						visit[nx][ny] = groupId;
					}
				}
				group[groupId++] = cnt;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				set<int> S;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
					S.insert(visit[nx][ny]);
				}

				int sum = 1;
				for (int s : S) sum += group[s];
				printf("%d", sum%10);
			}
			else printf("0");
		}
		printf("\n");
	}

	return 0;
}