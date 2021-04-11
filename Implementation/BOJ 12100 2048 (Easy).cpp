#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2:35PM ~ 4:23PM

int n, res = 0;

void up(int board[20][20]);
void down(int board[20][20]);
void left(int board[20][20]);
void right(int board[20][20]);

void backtracking(int board[20][20], int level) {
	// 0. 최댓값 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, board[i][j]);
		}
	}

	if (level == 5) return;
	
	// 1. 보드 카피
	int copyBoard[4][20][20];
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copyBoard[k][i][j] = board[i][j];
			}
		}
	}

	// 2. 상하좌우 이동
	up(copyBoard[0]);
	down(copyBoard[1]);
	left(copyBoard[2]);
	right(copyBoard[3]);

	// 3. backtracking
	for (int k = 0; k < 4; k++) {
		backtracking(copyBoard[k], level + 1);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	int board[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	backtracking(board, 0);

	cout << res;

	return 0;
}

void up(int board[20][20]) {
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[j][i] != 0) {
				Q.push(board[j][i]);
				board[j][i] = 0;
			}
		}
		for (int j = 0; !Q.empty(); j++) {
			int temp = Q.front();
			Q.pop();
			if (!Q.empty() && temp == Q.front()) {
				Q.pop();
				temp *= 2;
			}
			board[j][i] = temp;
		}
	}
}

void down(int board[20][20]) {
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[j][i] != 0) {
				Q.push(board[j][i]);
				board[j][i] = 0;
			}
		}

		for (int j = n - 1; !Q.empty(); j--) {
			int temp = Q.front();
			Q.pop();
			if (!Q.empty() && temp == Q.front()) {
				Q.pop();
				temp *= 2;
			}
			board[j][i] = temp;
		}
	}
}

void left(int board[20][20]) {
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				Q.push(board[i][j]);
				board[i][j] = 0;
			}
		}

		for (int j = 0; !Q.empty(); j++) {
			int temp = Q.front();
			Q.pop();
			if (!Q.empty() && temp == Q.front()) {
				Q.pop();
				temp *= 2;
			}
			board[i][j] = temp;
		}
	}

}

void right(int board[20][20]) {
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j] != 0) {
				Q.push(board[i][j]);
				board[i][j] = 0;
			}
		}
		for (int j = n - 1; !Q.empty(); j--) {
			int temp = Q.front();
			Q.pop();
			if (!Q.empty() && temp == Q.front()) {
				Q.pop();
				temp *= 2;
			}
			board[i][j] = temp;
		}
	}
}
