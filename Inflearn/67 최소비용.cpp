#include <stdio.h>
#include <limits.h>

using namespace std;

int n, m, min=INT_MAX;
int adjacent_matrix[21][21] = {0};
bool isVisited[21][21] = { false };

void dfs(int v, int sum) {
	if (v == n) {
		if (min > sum) min = sum;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (adjacent_matrix[v][i]> 0 && !isVisited[v][i]) {
				isVisited[v][i] = true;
				dfs(i, sum + adjacent_matrix[v][i]);
				isVisited[v][i] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adjacent_matrix[a][b] = c;
	}

	isVisited[1][1] = true;
	dfs(1, 0);

	printf("%d", min);

	return 0;
}