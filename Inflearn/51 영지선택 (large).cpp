#include <stdio.h>

using namespace std;

int territory[701][701] = { 0 };
int dp[701][701] = { 0 };

int main() {
	int height, width, h, w;
	scanf("%d %d", &height, &width);

	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			scanf("%d", &territory[i][j]);

	scanf("%d %d", &h, &w);

	int max = 0, size;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + territory[i][j];

			if (i >= h && j >= w) {
				size = dp[i][j] - dp[i - h][j] - dp[i][j - w] + dp[i - h][j - w];
				if (max < size) max = size;
			}
		}
	}

	printf("%d", max);

	return 0;
}