#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int> > island(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> island[i][j];
		}
	}

	int x = 1, y = 1, nx,ny, cnt=0;
	int dx[8] = { 0,0,-1,1, -1,-1,1,1 };
	int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

	queue<pair<int,int>> Q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (island[i][j] == 1) {
				island[i][j] = 0;
				Q.push({ i,j });
				cnt++;
				while (!Q.empty()) {
					x = Q.front().first;
					y = Q.front().second;
					Q.pop();

					for (int k = 0; k < 8; k++) {
						nx = x + dx[k];
						ny = y + dy[k];

						if (nx<1 || nx>n || ny<1 || ny>n) continue;
						if (island[nx][ny] == 1) {
							island[nx][ny] = 0;
							Q.push({ nx,ny });
						}
					}
				}
			}

		}
	}

	cout << cnt;
	


	return 0;
}
