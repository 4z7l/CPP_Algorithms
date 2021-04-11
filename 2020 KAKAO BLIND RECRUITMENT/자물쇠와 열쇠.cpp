#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 오후 5:02 ~ 6:14

vector<vector<int>> rotate_key(vector<vector<int>> key) {
	vector<vector<int>> new_key(key);
	int n = key.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_key[n - j - 1][i] = key[i][j];
		}
	}
	return new_key;
}

// key의 0,0이 lock의 x,y
bool dfs(vector<vector<int>> key, vector<vector<int>> lock) {
	int n = lock.size();
	int m = key.size();

	for (int x = -n + 1; x < n; x++) {
		for (int y = -n + 1; y < n; y++) {

			bool temp = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i - x < 0 || j - y < 0 || i - x>m - 1 || j - y>m - 1) {
						if (lock[i][j] != 1) {
							temp = false;
							break;
						}
					}
					else {
						if (lock[i][j] + key[i - x][j - y] != 1) {
							temp = false;
							break;
						}
					}
				}
			}

			if (temp) {
				return true;
			}
		}
	}

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	for (int i = 0; i < 4; i++) {
		key = rotate_key(key);
		if (dfs(key, lock)) return true;
	}

	return false;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });
	cout << solution({ {0,0,0},{0,0,0},{1,1,1} }, { {0,0,1},{1,1,1},{1,1,1} });

	return 0;
}
