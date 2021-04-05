#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int n, m;
short cheese[100][100];
bool visit[100][100];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int total_cheese = 0, last_cheese = 0;
	int time = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) total_cheese++;
		}
	}

	queue<pair<int, int> > Q;
	while (total_cheese > 0) {
		last_cheese = total_cheese;

		memset(visit, false, sizeof(visit));
		visit[0][0] = true;
		Q.push({ 0,0 });
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx<0 || nx>n || ny<0 || ny>m) continue;
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					if (cheese[nx][ny] == 0) Q.push({ nx,ny });
					else {
						cheese[nx][ny] = 0;
						total_cheese--;
					}
				}
			}
		}

		time++;
	}

	cout << time << '\n' << last_cheese;

	return 0;
}