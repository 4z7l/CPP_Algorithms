#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>* graph, int start, bool* visited) {
	if (visited[start] != true) {
		visited[start] = true;
		cout << start << ' ';
		for (auto it = graph[start].begin(); it != graph[start].end(); it++) {
			if (visited[*it] != true) {
				dfs(graph, *it, visited);
			}
		}
	}
	else return;
}

void bfs(vector<int>* graph, int start, int n) {
	bool* visited = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) visited[i] = false;

	queue<int> queue;

	visited[start] = true;
	queue.push(start);
	cout << start << ' ';

	if (graph[start].empty()) {
		cout << '\n';
		return;
	}

	while(!queue.empty()) {
		start = queue.front();
		queue.pop();

		if (graph[start].empty()) {
			cout << start << '\n';
			return;
		}

		for (auto it = graph[start].begin(); it != graph[start].end(); it++) {
			if (visited[*it] != true) {
				visited[*it] = true;
				queue.push(*it);
				cout << *it << ' ';
			}
		}
	}

	cout << '\n';
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n, m, start;
	cin >> n >> m >> start;

	int u, v;
	vector<int>* graph = new vector<int>[n + 1];

	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : ";
	//	for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
	//			cout << *it << ' ';
	//	}
	//	cout << endl;
	//}


	bool* visited = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) visited[i] = false;

	dfs(graph, start, visited);
	cout << '\n';
	bfs(graph, start, n);

	return 0;
}