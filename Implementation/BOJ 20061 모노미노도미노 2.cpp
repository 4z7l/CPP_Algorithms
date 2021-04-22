#include <iostream>
#include <vector>

using namespace std;

//9:51AM ~ 10:54AM

struct pos { int x, y; };

int board[10][10];
int score = 0;
vector<vector<pos>> block = { {{0,0},{0,0}}, {{0,0},{0,1}}, {{1,0},{0,0}} };

bool isGreenRange(int x, int y);
bool isBlueRange(int x, int y);
void put_block(int t, int x, int y);
void get_score();
void check_special();
void print();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int N, t, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		put_block(t, x, y);
		get_score();
		check_special();
	}

	int remainBlock = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) remainBlock++;
		}
	}
	cout << score << '\n';
	cout << remainBlock << '\n';
	return 0;
}

bool isGreenRange(int x, int y) {
	if (0 <= x && x < 10 && 0 <= y && y < 4 && board[x][y] == 0) return true;
	else return false;
}

bool isBlueRange(int x, int y) {
	if (0 <= x && x < 4 && 0 <= y && y < 10 && board[x][y] == 0) return true;
	else return false;
}

void put_block(int t, int x, int y) {
	int b = t - 1;

	//초록색으로 이동
	pos p1 = { x,y }, p2 = { x + block[b][0].x,y + block[b][1].y };
	while (isGreenRange(p1.x + 1, p1.y)
		&& isGreenRange(p2.x + 1, p2.y)) {
		p1.x += 1; p2.x += 1;
	}
	board[p1.x][p1.y] = 1;
	board[p2.x][p2.y] = 1;

	//파랑색으로 이동
	p1 = { x,y }, p2 = { x + block[b][0].x,y + block[b][1].y };
	while (isBlueRange(p1.x, p1.y + 1)
		&& isBlueRange(p2.x, p2.y + 1)) {
		p1.y += 1; p2.y += 1;
	}
	board[p1.x][p1.y] = 1;
	board[p2.x][p2.y] = 1;
}

void get_score() {
	//초록 검사
	for (int i = 4; i < 10; i++) {
		bool isRowFull = true;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) { isRowFull = false; break; }
		}
		if (isRowFull) {
			for (int j = 0; j < 4; j++) board[i][j] = 0;
			for (int j = i; j > 4; j--) {
				for (int k = 0; k < 4; k++) {
					board[j][k] = board[j - 1][k];
				}
			}
			score++;
		}
	}

	//파랑 검사
	for (int i = 4; i < 10; i++) {
		bool isColumnFull = true;
		for (int j = 0; j < 4; j++) {
			if (board[j][i] == 0) { isColumnFull = false; break; }
		}
		if (isColumnFull) {
			for (int j = 0; j < 4; j++) board[j][i] = 0;
			for (int j = i; j > 4; j--) {
				for (int k = 0; k < 4; k++) {
					board[k][j] = board[k][j - 1];
				}
			}
			score++;
		}
	}
}

void check_special() {
	//초록 검사
	int isSpecialGreenExist[2] = { false, false };
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 1) {
				isSpecialGreenExist[i - 4] = true;
				break;
			}
		}
	}
	int specialGreenCnt = 0;
	for (int i = 0; i < 2; i++) {
		if (isSpecialGreenExist[i]) specialGreenCnt++;
	}
	if (specialGreenCnt > 0) {
		for (int j = 9; j >= 4; j--) {
			for (int k = 0; k < 4; k++) {
				board[j][k] = board[j - specialGreenCnt][k];
			}
		}
	}


	//파랑 검사
	int isSpecialBlueExist[2] = { false, false };
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[j][i] == 1) {
				isSpecialBlueExist[i - 4] = true;
				break;
			}
		}
	}
	int specialBlueCnt = 0;
	for (int i = 0; i < 2; i++) {
		if (isSpecialBlueExist[i]) specialBlueCnt++;
	}
	if (specialBlueCnt > 0) {
		for (int j = 9; j >= 4; j--) {
			for (int k = 0; k < 4; k++) {
				board[k][j] = board[k][j - specialBlueCnt];
			}
		}
	}
}

void print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 4; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}