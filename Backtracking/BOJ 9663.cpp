#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, cnt = 0;
int chess[15][15];
bool isUsed1[15];
bool isUsed2[30];
bool isUsed3[30];

void backtracking(int row) {
	if (row == n) {
		cnt++;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!isUsed1[i] && !isUsed2[i + row] && !isUsed3[row - i + n - 1]) {
				isUsed1[i] = true;
				isUsed2[i + row] = true;
				isUsed3[row - i + n - 1] = true;
				backtracking(row + 1);
				isUsed1[i] = false;
				isUsed2[i + row] = false;
				isUsed3[row - i + n - 1] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	backtracking(0);

	cout << cnt;

	return 0;
}
