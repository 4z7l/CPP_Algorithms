#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//3:00PM ~ 3:37PM ~ 4:29PM

int dp[1001][1001] = { 0, };

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str2[i - 1] == str1[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int x = m, y = n;
	string res = "";
	while (x>0 && y>0 && dp[x][y] != 0) {
		if (str2[x - 1] == str1[y - 1]) {
			res += str1[y - 1];
			x--; y--;
		}
		else {
			if (dp[x][y] == dp[x][y - 1])  y--;
			else if (dp[x][y] == dp[x - 1][y]) x--;
		}
	}

	cout << dp[m][n] << '\n';
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
	}

	return 0;
}
