#include <stdio.h>
#include <stack>

using namespace std;

int set[10];
bool isSubsetExist = false;
int sum = 0, n = 0;

void dfs(int pos, int subsum) {
	if (pos >= n) return;
	if (isSubsetExist) return;

	if (subsum * 2 == sum) {
		isSubsetExist = true;
		return;
	}

	dfs(pos + 1, subsum);
	dfs(pos + 1, subsum + set[pos]);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &set[i]);
		sum += set[i];
	}

	dfs(0, 0);

	if (isSubsetExist) printf("YES");
	else printf("NO");

	return 0;
}