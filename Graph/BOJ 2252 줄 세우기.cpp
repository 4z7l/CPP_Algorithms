#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m;

	vector<int> graph[32001];
	vector<int> degree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	queue<int> pQ;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) pQ.push(i);
	}
	int v, w;
	while (!pQ.empty()) {
		v = pQ.front();
		cout << v << ' ';
		pQ.pop();

		for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
			w = (*it);
			degree[w]--;
			if (degree[w] == 0) pQ.push(w);
		}
	}

	return 0;
}