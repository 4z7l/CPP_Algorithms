#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int sudoku[9][9];
vector<pair<int, int> > blank;

void print_sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout<< sudoku[i][j]<<' ';
		}
		cout << '\n';
	}
}

bool check_sudoku(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][y] == sudoku[i][y] && x!=i) return false;
		if (sudoku[x][y] == sudoku[x][i] && y!=i) return false;
	}

	int sx = x / 3;
	int sy = y / 3;
	for (int i = 3 * sx; i < 3 * sx + 3; i++) {
		for (int j = 3 * sy; j < 3 * sy + 3; j++){
			if (sudoku[i][j] == sudoku[x][y] && (i != x && j != y)) return false;
		}
	}
	return true;
}

void backtracking(int x) {
	if (x == blank.size()) {
		print_sudoku();
		exit(0);
	}
	if (sudoku[blank[x].first][blank[x].second] == 0) {
		for (int k = 1; k <= 9; k++) {
			sudoku[blank[x].first][blank[x].second] = k;
			if(check_sudoku(blank[x].first,blank[x].second)) backtracking(x + 1);
			sudoku[blank[x].first][blank[x].second] = 0;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) blank.push_back({ i,j });
		}
	}

	backtracking(0);

	return 0;
}