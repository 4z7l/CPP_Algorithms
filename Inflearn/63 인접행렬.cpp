#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> adjacent_matrix(n + 1, vector<int>(n + 1, 0));

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adjacent_matrix[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", adjacent_matrix[i][j]);
		}
		printf("\n");
	}


	return 0;
}
