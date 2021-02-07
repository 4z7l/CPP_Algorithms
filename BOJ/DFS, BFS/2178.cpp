#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n>>m;

	vector<string> miro;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		miro.push_back(input);
	}

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	int x = 0, y = 0, nx,ny;

	queue<pair<int, int>> Q;
	vector<vector<int>> dist(n+1, vector<int>(m+1, 0));
	Q.push({ x, y });
	dist[x][y] = 1;

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		if (x == n - 1 && y == m - 1) break;

		if (miro[x][y] == '1') {
			miro[x][y] = '0';
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
				if (miro[nx][ny] == '1') {
					dist[nx][ny] = dist[x][y] + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}

	cout << dist[n-1][m-1];

	return 0;
}
