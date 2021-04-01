#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>* graph, int start, bool * visited, int &cnt) {
	if (visited[start] != true) {
		cnt++;
		visited[start] = true;
		for (auto it = graph[start].begin(); it != graph[start].end(); it++) {
			if(visited[*it]!=true)
				dfs(graph, *it, visited, cnt);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n, m, u, v;
	cin >> n;
	cin >> m;

	vector<int>* graph = new vector<int>[n + 1];

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
		
	bool* visited = new bool[n + 1];
	for (int i = 0; i < n+1; i++) {
		visited[i] = false;
	}
	int cnt = 0;
	dfs(graph, 1, visited, cnt);
	cout << cnt-1;

	return 0;
}