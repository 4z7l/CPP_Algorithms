#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;

int n, m, min_cost = INT_MAX;
vector<pair<int, int>> graph[21];
bool isVisited[21][21] = { false };

void dfs(int v, int sum) {
	if (v == n) {
		if (min_cost > sum) min_cost = sum;
	}
	else {
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i].first;
			if (graph[v][i].second > 0 && !isVisited[v][next]) {
				isVisited[v][next] = true;
				dfs(next, sum + graph[v][i].second);
				isVisited[v][next] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}

	isVisited[1][1] = true;
	dfs(1, 0);

	printf("%d", min_cost);

	return 0;
}