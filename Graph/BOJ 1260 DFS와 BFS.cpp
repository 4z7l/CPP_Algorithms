#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[1'001];
bool visited[1'001];

void dfs(int start) {
	for (int v : graph[start]) {
		if (!visited[v]) {
			cout << v << ' ';
			visited[v] = true;
			dfs(v);
		}
	}
}

void bfs(int start) {
	queue<int> Q;

	visited[start] = true;
	Q.push(start);
	cout << start << ' ';

	while (!Q.empty()) {
		start = Q.front();
		Q.pop();

		for (int v : graph[start]) {
			if (!visited[v]) {
				cout << v << ' ';
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int start;
	cin >> n >> m >> start;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	memset(visited, false, sizeof(visited));
	cout << start << ' ';
	visited[start] = true;
	dfs(start);
	cout << '\n';

	memset(visited, false, sizeof(visited));
	bfs(start);

	return 0;
}