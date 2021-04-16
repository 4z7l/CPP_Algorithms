#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
vector<int> graph[101];
vector<bool> visited(101, false);

void dfs(int start) {
	for (int v : graph[start]) {
		if (visited[v] != true) {
			visited[v] = true;
			cnt++;
			dfs(v);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n, m, u, v;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;
	dfs(1);
	cout << cnt;

	return 0;
}