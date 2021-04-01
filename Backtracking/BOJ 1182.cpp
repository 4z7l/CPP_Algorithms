#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, s, cnt = 0;
int arr[20];

void backtracking(int pos, int sum) {
	if (pos == n) {
		if (sum == s) cnt++;
	}
	else {
		backtracking(pos + 1, sum);
		backtracking(pos + 1, sum + arr[pos]);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	backtracking(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
	return 0;
}
