#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define HOUSE '1'
#define GROUND '0'
#define VISITED 1
#define NOT_VISITED 0

using namespace std;

int bfs(string* danzi, bool** visited, int x, int y, int n) {
	queue<pair<int, int>> queue;
	int direction[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	int cnt = 1;
	visited[x][y] = VISITED;
	queue.push(make_pair(x, y));

	while (!queue.empty()) {
		x = queue.front().first;
		y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + direction[i][1];
			int nextY = y + direction[i][0];

			if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
				if (danzi[nextX][nextY] == HOUSE && visited[nextX][nextY] == NOT_VISITED) {
					visited[nextX][nextY] = VISITED;
					queue.push(make_pair(nextX, nextY));
					cnt++;
				}
			}
		}
	}

	return cnt;
}


int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string* danzi = new string[n];
	for (int i = 0; i < n; i++)
		cin >> danzi[i];

	bool** visited = new bool* [n];
	for (int i = 0; i < n; i++)
		visited[i] = new bool[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = NOT_VISITED;

	vector<int> arr;
	int x = 0, y = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (danzi[i][j] == HOUSE && visited[i][j]==NOT_VISITED) {
				arr.push_back(bfs(danzi, visited, i, j, n));
			}
		}
	}

	cout << arr.size()<<'\n';
	sort(arr.begin(), arr.end());

	for (auto it = arr.begin(); it != arr.end(); it++)
		cout << *it<<'\n';

	return 0;
}