#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n;

	vector<vector<int> > friends(n + 1, vector<int>(n + 1, 100));

	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		friends[a][b] = 1;
		friends[b][a] = 1;
	}

	//플로이드 와샬 알고리즘
	for (int i = 1; i <= n; i++) {
		friends[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
			}
		}
	}

	int chairman = 100, temp = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		temp = 0;
		for (int j = 1; j <= n; j++) {
			if (friends[i][j] == 100) continue;
			temp = max(temp, friends[i][j]);
		}
		friends[i][0] = temp;
		if (chairman > temp) {
			chairman = temp;
			cnt = 1;
		}
		else if (chairman == temp) {
			cnt++;
		}
	}

	cout << chairman << ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (friends[i][0] == chairman) {
			cout << i << ' ';
		}
	}

	return 0;
}