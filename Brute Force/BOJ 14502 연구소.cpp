#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//4:35~4:53

struct pos { int x, y; };

vector<pos> virus;
vector<pos> blank;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int spread_virus(vector<pos> wall, vector<vector<int>> board) {
	// 2. 바이러스 퍼뜨리기
	for (int i = 0; i < wall.size(); i++) {
		board[wall[i].x][wall[i].y] = 1;
	}

	int N = board.size(); 
	int M = board[0].size();

	vector< vector<bool>> visit(N, vector<bool>(M, false));
	queue<pos> Q;
	for (int i = 0; i < virus.size(); i++) {
		Q.push(virus[i]);
		visit[virus[i].x][virus[i].y] = true;
	}

	int x, y, nx, ny;
	while (!Q.empty()) {
		x = Q.front().x; y = Q.front().y; 
		Q.pop();

		for (int d = 0; d < 4; d++) {
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1 || visit[nx][ny] ) continue;
			if (board[nx][ny] == 0) {
				board[nx][ny] = 2;
				visit[nx][ny] = true;
				Q.push({ nx,ny });

			}

		}
	}

	// 3. 안전영역 구하기
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;
	vector<vector<int> > board(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i,j });
			else if (board[i][j] == 0) blank.push_back({ i,j });
		}
	}

	// 1. 벽 3개 세우기
	vector<int> comb(blank.size(), 0 );
	for (int i = 0; i < 3; i++) comb[i] = 1;

	int res = 0;
	do {
		vector<pos> wall;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1) wall.push_back(blank[i]);
		}
		int ret = spread_virus(wall, board);
		if (res < ret) res = ret;
	} while (prev_permutation(comb.begin(), comb.end()));

	cout << res;

	return 0;
}