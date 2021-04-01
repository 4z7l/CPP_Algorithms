#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, L;
int board[101][101] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct pos{
	int x, y;
};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = 2;
	}

	cin >> L;
	char ch;
	vector<pair<int, char>> movements;
	for (int i = 0; i < L; i++) {
		cin >> a >> ch;
		movements.push_back({ a,ch });
	}

	int time = 0;
	int nx = 1, ny = 1, dir = 0;;

	deque<pos> dQ;
	dQ.push_front({ nx,ny });
	board[nx][ny] = 1;

	int m_ind = 0;
	while (true) {
		time++;

		nx = dQ.front().x + dx[dir];
		ny = dQ.front().y + dy[dir];
		if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny] == 1) break;

		if (board[nx][ny] == 0) {
			board[dQ.back().x][dQ.back().y] = 0;
			dQ.pop_back();
		}
		dQ.push_front({ nx,ny });
		board[nx][ny] = 1;

		if (m_ind<L && movements[m_ind].first == time) {
			if (movements[m_ind].second == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			m_ind++;
		}
	}

	cout << time;

	return 0;
}
