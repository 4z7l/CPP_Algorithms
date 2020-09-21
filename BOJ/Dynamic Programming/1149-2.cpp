#include <cstdio>

using namespace std;

#define MAX_SIZE 1000

int getMinimumIndexExceptX(int* rgb, int x) {
	int min = __INT_MAX__, mind;
	for (int i = 0; i < 3; i++) {
		if (i == x) continue;
		if (rgb[i] < min) {
			min = rgb[i];
			mind = i;
		}
	}
	return mind;
}

int main() {

	int houses[MAX_SIZE][3];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &houses[i][j]);
		}
	}

	int ind;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			ind = getMinimumIndexExceptX(houses[i - 1], j);
			houses[i][j] += houses[i - 1][ind];
		}
	}

	ind = getMinimumIndexExceptX(houses[n - 1], -1);
	printf("%d\n", houses[n - 1][ind]);

	return 0;
}