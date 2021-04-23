#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

// 10:11 ~ 11:7

struct pos { int x, y;};
struct info {
	int x, y, dist;
	bool operator<(const info& i) const {
		if (dist == i.dist) {
			if (x == i.x) return y > i.y;
			else return x > i.x;
		}
		else return dist > i.dist;
	}
};

pos rider;
int board[21][21];
vector<pos> destination;
int N, M, gas;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void input();
bool find_customer();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	input();
	while (M > 0) {
		if(find_customer()) M--;
		else {
			cout << -1;
			return 0;
		}
	}

	cout << gas;
	return 0;
}

void input() {
	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> gas;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) board[i][j] = -1;
		}
	}
	cin >> rider.x >> rider.y;
	int a, b, c, d;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c >> d;
		destination.push_back({ c,d });
		board[a][b] = i;
	}
}

bool find_customer() {
	bool visit[21][21] = {false,};

	//승객찾기
	int x = 0, y = 0, dist = 0;

	priority_queue<info> pQ;
	pQ.push({ rider.x,rider.y,0 });
	visit[rider.x][rider.y] = true;
	
	int customerInd=-1;
	while (!pQ.empty()) {
		x = pQ.top().x; y = pQ.top().y; dist = pQ.top().dist;
		pQ.pop();

		if (board[x][y] > 0) {
			customerInd = board[x][y]-1;
			break;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<1 || nx>N || ny<1 || ny>N || visit[nx][ny] || board[nx][ny]==-1) continue;
			pQ.push({ nx,ny,dist + 1 });
			visit[nx][ny] = true;
		}
	}
	if (customerInd == -1) return false;

	int sx = x, sy = y;
	int go_to_customer_cost = dist;

	//데려다주기
	memset(visit, false, sizeof(visit));

	queue<info> Q;
	Q.push({ x,y,0 });
	visit[x][y] = true;

	while (!Q.empty()) {
		x = Q.front().x; y = Q.front().y; dist = Q.front().dist;
		Q.pop();

		if (x == destination[customerInd].x && y == destination[customerInd].y)  break;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<1 || nx>N || ny<1 || ny>N || visit[nx][ny] || board[nx][ny] == -1) continue;
			Q.push({ nx,ny,dist + 1 });
			visit[nx][ny] = true;
		}
	}
	if (x != destination[customerInd].x || y != destination[customerInd].y) return false;

	if (gas - go_to_customer_cost - dist >= 0) {
		rider = { x,y };
		board[sx][sy] = 0;
		gas = gas - go_to_customer_cost + dist;
		return true;
	}
	else return false;
}
