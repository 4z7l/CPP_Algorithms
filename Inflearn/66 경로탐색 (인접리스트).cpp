#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
vector<int> adjacent_list[21];
bool isVisited[21] = { false };

void dfs(int v) {
	if (v == n) {
		cnt++;
	}
	else {
		auto it = adjacent_list[v].begin();
		while (it != adjacent_list[v].end()) {
			int next = *it;
			if (!isVisited[next]) {
				isVisited[next] = true;
				dfs(next);
				isVisited[next] = false;
			}
			it++;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	int a, b;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adjacent_list[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		sort(adjacent_list[i].begin(), adjacent_list[i].end());
	}

	isVisited[1] = true;
	dfs(1);

	printf("%d", cnt);

	return 0;
}