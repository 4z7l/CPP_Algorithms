#include <stdio.h>
#include <vector>

using namespace std;

int map[52][52] = { 0 };
bool low[52][52] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	bool isBonguri;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			isBonguri = true;
			if (low[i][j]) continue;

			for (int k = 0; k < 4; k++) {
				if (map[i][j] <= map[i + dx[k]][j + dy[k]]) {
					isBonguri = false;
					low[i][j] = true;
					break;
				}
			}
			if (isBonguri) {
				cnt++;
				for (int k = 0; k < 4; k++) {
					low[i + dx[k]][j + dy[k]] = true;
				}
			}
		}

	}

	printf("%d", cnt);

	return 0;
}
