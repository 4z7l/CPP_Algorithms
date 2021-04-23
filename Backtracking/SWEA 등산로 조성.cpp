#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos { int x, y; };
struct info { int x, y, dist, check = 0; };

int N, K, res=0;
int board[10][10];
bool visit[10][10];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void make_road(int x, int y, int check, int dist) {
	res = max(res, dist);

	//cout << x << ", " << y << "¹æ¹® ("<<check<<") : " << dist<<' '<<res << '\n';

	int nx, ny;
	for (int d = 0; d < 4; d++) {
		nx = x + dx[d];
		ny = y + dy[d];
		if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1 || visit[nx][ny]) continue;
		// ±ðÀ» ¶§
		if (board[nx][ny] >= board[x][y] && check==0) {
			for (int k = 1; k <= K; k++) {
				if (board[nx][ny] - k < board[x][y]) {
					visit[nx][ny] = true;
					board[nx][ny] -= k;
					make_road(nx, ny, 1, dist+1);
					board[nx][ny] += k;
					visit[nx][ny] = false;
				}
			}
		}
		else if (board[nx][ny] < board[x][y]) {
			visit[nx][ny] = true;
			make_road(nx, ny, check, dist+1);
			visit[nx][ny] = false;
		}
	}

}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		res = 0;
		cin >> N >> K;

		int maxBonguriSize = 0;
		vector<pos> maxBonguri;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (maxBonguriSize < board[i][j]) {
					maxBonguriSize = board[i][j];
					maxBonguri.clear();
					maxBonguri.push_back({ i,j });
				}
				else if (maxBonguriSize == board[i][j]) {
					maxBonguri.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < maxBonguri.size(); i++) {
			int x = maxBonguri[i].x;
			int y = maxBonguri[i].y;
			memset(visit, false, sizeof(visit));
			visit[x][y] = true;
			make_road(x, y, 0, 1);
		}
		//cout << res<<'\n';
		cout << "#"<<tc<<' '<<res<<'\n';
	}


	return 0;
}
