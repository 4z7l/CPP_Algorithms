#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int res = INT_MAX;

void dfs(int n, int cnt) {
	if (cnt > res) return;
	if (n == 1) {
		if (res > cnt) res = cnt;
	}
	else {
		if (n % 3 == 0) dfs(n / 3, cnt + 1);
		if (n % 2 == 0) dfs(n / 2, cnt + 1);
		dfs(n - 1, cnt + 1);
	}
}

int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	dfs(n, 0);

	cout << res;

	return 0;
}
