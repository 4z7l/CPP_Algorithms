#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define CABBAGE 1
#define GROUND 0
#define VISITED true
#define NOT_VISITED false

using namespace std;

int** farm;
bool** visited;
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m, k;

void dfs(int sx, int sy) {
	int nx, ny;

	visited[sx][sy] = VISITED;

	for (int i = 0; i < 4; i++) {
		nx = sx + direction[i][0];
		ny = sy + direction[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (farm[nx][ny] == CABBAGE && visited[nx][ny] == NOT_VISITED) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int testcase;
	cin >> testcase;


	while (testcase > 0) {
		cin >> n >> m >> k;

		/* initiate array */
		farm = new int* [n];
		for (int i = 0; i < n; i++) {
			farm[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				farm[i][j] = GROUND;

		visited = new bool* [n];
		for (int i = 0; i < n; i++) {
			visited[i] = new bool[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				visited[i][j] = NOT_VISITED;


		/* get location of cabbage */
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			farm[x][y] = CABBAGE;
		}


		/* dfs */
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j] == CABBAGE && visited[i][j] == NOT_VISITED) {
					dfs(i, j); 
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		testcase--;

		for (int i = 0; i < n; i++) 
			delete[] farm[i];
		delete [] farm;
		
		for (int i = 0; i < n; i++)
			delete[] visited[i];
		delete [] visited;
	}

	return 0;
}