#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int operators[4];
int n, minRes = INT_MAX, maxRes= INT_MIN;
int arr[12];

void dfs(int pos, int sum) {
	if (pos == n) {
		if (minRes > sum) minRes = sum;
		if (maxRes < sum) maxRes = sum;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (operators[i] > 0) {
				operators[i]--;
				switch (i) {
				case 0: dfs(pos + 1, sum + arr[pos + 1]); break;
				case 1: dfs(pos + 1, sum - arr[pos + 1]); break;
				case 2: dfs(pos + 1, sum * arr[pos + 1]); break;
				case 3: dfs(pos + 1, sum / arr[pos + 1]); break;
				default: break;
				}
				operators[i]++;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	dfs(1, arr[1]);

	cout << maxRes << '\n';
	cout << minRes << '\n';

	return 0;
}