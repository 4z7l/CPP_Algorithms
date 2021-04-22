#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int board[125][125];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct pos {
	int x, y, dist;
	bool operator<(const pos& p) const {
		return dist > p.dist;
	}
};

int solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>> visit(N, vector<int>(N, 2'147'000'000));
	priority_queue<pos> pQ;
	pQ.push({ 0,0,board[0][0] });
	visit[0][0] = board[0][0];

	int x, y, dist;
	while (!pQ.empty()) {
		x = pQ.top().x;
		y = pQ.top().y;
		dist = pQ.top().dist;
		pQ.pop();

		if (visit[x][y] > dist) continue;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;

			if (visit[nx][ny] > board[nx][ny] + dist) {
				visit[nx][ny] = board[nx][ny] + dist;
				pQ.push({ nx,ny, visit[nx][ny] });
			}
		}
		
	}
	return visit[N - 1][N - 1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);

	for (int i = 1;; i++) {
		cin >> N;
		if (N == 0) break;
		cout << "Problem " <<i<<": "<< solve()<<'\n';
	}

	return 0;
}
