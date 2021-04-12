#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//3:00PM ~ 3:37PM

string dp[1000][1000] = {"",};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = "";
		}
	}

	string res = "";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			string x, y,z;
			if (i > 0) x = dp[i - 1][j];
			else x = "";

			if (j > 0) y = dp[i][j - 1];
			else y = "";

			if (i > 0 && j > 0) z = dp[i - 1][j - 1];
			else z = "";

			if (str2[i] == str1[j]) {
				dp[i][j] = z + str2[i];
			}
			else {
				if (x.size() > y.size()) dp[i][j] = x ;
				else dp[i][j] = y;
			}

			if (res.size() < dp[i][j].size()) {
				res = dp[i][j];
			}
		}
	}

	cout << res.size() << '\n';
	cout << res << '\n';

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {

	//		cout << dp[i][j] << '\t';
	//	}
	//	cout << '\n';
	//}

	return 0;
}
