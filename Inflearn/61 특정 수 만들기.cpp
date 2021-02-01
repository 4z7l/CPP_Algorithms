#include <stdio.h>
#include <stack>

using namespace std;

int n, m, cnt = 0;
int elements[10];

void dfs(int pos, int sum) {
	if (pos >= n) {
		if (sum == m)cnt++;
	}
	else {
		dfs(pos + 1, sum + elements[pos]);
		dfs(pos + 1, sum);
		dfs(pos + 1, sum - elements[pos]);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) 
		scanf("%d", &elements[i]);

	dfs(0, 0);

	if (cnt == 0) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;
}