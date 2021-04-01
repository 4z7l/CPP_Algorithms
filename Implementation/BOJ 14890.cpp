#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int map[200][100];
int N, L, res=0;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> L;

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			map[i + N][j] = map[j][i];
		}
	}

	int cnt = 1;
	for (i = 0; i < N*2; i++) {
		cnt = 1;
		for (j = 0; j < N-1; j++) {
			if (map[i][j] == map[i][j + 1]) cnt++;
			else if (map[i][j] + 1 == map[i][j + 1] && cnt >= L) cnt = 1;
			else if (map[i][j] - 1 == map[i][j + 1] && cnt >= 0) cnt = -L + 1;
			else break;
		}
		if (j == N - 1 && cnt>=0) res++;
	}

	cout << res;

	return 0;
}