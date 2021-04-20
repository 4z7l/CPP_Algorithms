#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
int n, m, t;
int A[51][51];
int dA[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void run_upper_cleaner(int x) {
	int i = x - 1, j = 1;

	while (i > 1) {
		A[i][j] = A[i - 1][j];
		i--;
	}
	while (j < m) {
		A[i][j] = A[i][j + 1];
		j++;
	}
	while (i < x) {
		A[i][j] = A[i + 1][j];
		i++;
	}
	while (j > 1) {
		A[i][j] = A[i][j - 1];
		j--;
	}
	A[x][2] = 0;
}

void run_lower_cleaner(int x) {
	int i = x + 1, j = 1;
	while (i < n) {
		A[i][j] = A[i + 1][j];
		i++;
	}
	while (j < m) {
		A[i][j] = A[i][j + 1];
		j++;
	}
	while (i > x) {
		A[i][j] = A[i - 1][j];
		i--;
	}
	while (j > 1) {
		A[i][j] = A[i][j - 1];
		j--;
	}
	A[x][2] = 0;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m >> t;

	vector<int> cleaner;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1) cleaner.push_back(i);
		}
	}

	int x, y, cnt = 0;
	while (t > 0) {
		// 1. 미세먼지 확산
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dA[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cnt = 0;
				if (A[i][j] < 5) continue;

				for (int k = 0; k < 4; k++) {
					x = i + dx[k];
					y = j + dy[k];

					if (x<1 || x> n || y<1 || y>m) continue;
					if (A[x][y] == -1) continue;

					cnt++;
					dA[x][y] += A[i][j] / 5;
				}
				A[i][j] -= (A[i][j] / 5) * cnt;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				A[i][j] += dA[i][j];
			}
		}

		// 2. 공기청정기 작동
		run_upper_cleaner(cleaner[0]);
		run_lower_cleaner(cleaner[1]);

		t--;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] == -1) continue;
			sum += A[i][j];
		}
	}
	cout << sum;

	return 0;
}
