#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 21.04.07 4:47PM ~ 5:13PM

string sudoku[9];
vector<pair<int, int >> blank;

bool check_row(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][y] == sudoku[x][i] && i != y)
			return false;
	}
	return true;
}

bool check_column(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][y] == sudoku[i][y] && i != x)
			return false;
	}
	return true;
}

bool check_square(int x, int y) {
	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++) {
		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) {
			if (sudoku[x][y] == sudoku[i][j] && (x != i && y != j))
				return false;
		}
	}
	return true;
}

bool isSudoku(int x, int y) {
	if (check_row(x, y) && check_column(x, y) && check_square(x, y))
		return true;
	return false;
}

void print_sudoku() {
	for (int i = 0; i < 9; i++) {
		cout << sudoku[i] << '\n';
	}
}

void backtracking(int ind) {
	if (ind == blank.size()) {
		print_sudoku();
		exit(0);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int x = blank[ind].first;
		int y = blank[ind].second;
		sudoku[x][y] = i + '0';
		if (isSudoku(x, y)) backtracking(ind + 1);
		sudoku[x][y] = '0';
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		cin >> sudoku[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == '0') {
				blank.push_back({ i,j });
			}
		}
	}

	backtracking(0);

	return 0;
}