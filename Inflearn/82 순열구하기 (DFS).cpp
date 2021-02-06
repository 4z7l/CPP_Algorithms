#include <stdio.h>
#include <vector>

using namespace std;

int n, r;
int numbers[16];
int result[16];
bool isChecked[16] = { false };
int cnt = 0;

void dfs(int pos) {
	if (pos == r) {
		for (int i = 0; i < pos; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		cnt++;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!isChecked[i]) {
				result[pos] = numbers[i];
				isChecked[i] = true;
				dfs(pos+1);
				isChecked[i] = false;
			}
		}
	}

}

int main() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &numbers[i]);
	}

	dfs(0);

	printf("%d", cnt);

	return 0;
}