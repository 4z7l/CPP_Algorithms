#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 7:29 ~ 8:10

struct ball {
	int r, c, m, s, d;
	//행 열 질량 속력 방향
};

int dx[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dy[8] = {  0,  1, 1, 1, 0, -1, -1, -1 };


vector<ball> fire;
vector<ball> board[51][51];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M, K;
	cin >> N >> M >> K;

	int r, c, m, s, d;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		fire.push_back({ r,c,m,s,d });
	}

	for (int k = 0; k < K; k++) {
		for (int f = 0; f < fire.size(); f++) {
			r = fire[f].r;
			c = fire[f].c;
			m = fire[f].m;
			s = fire[f].s;
			d = fire[f].d;

			int nr = r, nc = c;
			for (int speed = 0; speed < s; speed++) {
				nr += dx[d]; nc += dy[d];
				if (nr == N + 1) nr = 1;
				else if (nr == 0) nr = N;
				if (nc == N + 1) nc = 1;
				else if (nc == 0) nc = N;
			}
			board[nr][nc].push_back({ nr,nc,m,s,d });
		}


		vector<ball> new_fire;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j].empty()) continue;
				else if (board[i][j].size() == 1) {
					new_fire.push_back(board[i][j][0]);
				}
				else {
					int mSum = 0, sSum = 0;
					bool isAllHol = true, isAllZzak = true;
					for (int b = 0; b < board[i][j].size(); b++) {
						mSum += board[i][j][b].m;
						sSum += board[i][j][b].s;
						if (board[i][j][b].d % 2 == 0) isAllHol = false;
						else isAllZzak = false;
					}
					mSum /= 5;
					if (mSum > 0) {
						sSum /= board[i][j].size();
						if (isAllZzak|| isAllHol) {
							for (int nd : {0, 2, 4, 6}) {
								new_fire.push_back({ i,j,mSum, sSum, nd });
							}
						}
						else {
							for (int nd : {1, 3, 5, 7}) {
								new_fire.push_back({ i,j,mSum, sSum, nd });
							}
						}
					}
				}

			}
		}

		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
				board[i][j].clear();
		fire.clear();
		for (ball nb : new_fire) {
			fire.push_back(nb);
		}
	}

	int res = 0;
	for (ball b : fire) {
		res += b.m;
	}

	cout << res;

	return 0;
}