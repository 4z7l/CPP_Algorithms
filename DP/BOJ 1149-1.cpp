#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define MAX_SIZE 1000

int min(int a, int b) { return a < b ? a : b; }

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int houses[MAX_SIZE][3];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> houses[i][j];
		}
	}

	int ind;
	for (int i = 1; i < n; i++) {
		houses[i][0] += min(houses[i - 1][1], houses[i - 1][2]);
		houses[i][1] += min(houses[i - 1][0], houses[i - 1][2]);
		houses[i][2] += min(houses[i - 1][0], houses[i - 1][1]);
	}

	int min = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (houses[n - 1][i] < min) min = houses[n - 1][i];
	}
	cout << min << '\n';

	return 0;
}