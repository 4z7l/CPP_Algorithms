#include <iostream>
#include <vector>

using namespace std;

// 4:38PM ~ 5:47PM

struct pos { int x = 0, y = 0; };
struct sea { int id = 0, smell = 0; };

struct Shark {
	int x = 0, y = 0; //���� ����
	int dir = 0; // ���� �����ִ� ����
	int dp[4][4] = { 0, }; // ���� �켱����
	bool dead = false;
};

// �� �� �� ��
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N, M, K;
sea board[20][20];
Shark shark[401];
int remainShark = 0;

// function prototype
void input();
void print();
void move_shark();
void remove_smell();
void remain_smell();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	input();

	for (int t = 0; t <= 1000; t++) {
		remain_smell();
		move_shark();
		remove_smell();
		//print();
		if (remainShark == 1) {
			cout << t << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}

void input() {
	cin >> N >> M >> K;
	remainShark = M;

	// ���� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].id;
			if (board[i][j].id > 0) {
				shark[board[i][j].id].x = i;
				shark[board[i][j].id].y = j;
			}
		}
	}

	// �� �ٶ󺸰� �ִ� ����
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].dir;
		shark[i].dir--;
	}

	// ����� ���� �켱����
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> shark[i].dp[j][k];
				shark[i].dp[j][k]--;
			}
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "( " << board[i][j].id << ", " << board[i][j].smell << ")\t";
		}
		cout << '\n';
	}
	cout << "���� ��� : " << remainShark << "����\n\n";
}

void move_shark() {
	int x, y, nx, ny, nd, current_diretion;
	// ��� �̵�
	for (int s = 1; s <= M; s++) {
		if (shark[s].dead) continue;

		x = shark[s].x;
		y = shark[s].y;
		current_diretion = shark[s].dir;

		//����ĭ ã��
		bool isBlankExist = false;
		int nnx=-1, nny=-1, nnd;
		for (int i = 0; i < 4; i++) {
			int d = shark[s].dp[current_diretion][i];
			nx = x + dx[d];
			ny = y + dy[d];

			if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
			if (board[nx][ny].smell == 0) { 
				isBlankExist = true; nd = d;
				break; 
			}
			else if (board[nx][ny].id == s && nnx==-1 && nny ==-1 ) {
				nnx = nx; nny = ny; nnd = d;
			}
		}

		// �̵��ϱ�
		if (isBlankExist) {
			shark[s].x = nx;
			shark[s].y = ny;
			shark[s].dir = nd;
		}
		else if (nnx != -1 && nny != -1) {
			shark[s].x = nnx;
			shark[s].y = nny;
			shark[s].dir = nnd;
		}
	}
}

void remove_smell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].id > 0 && board[i][j].smell>0) {
				board[i][j].smell--;
				if (board[i][j].smell == 0)board[i][j].id = 0;
			}
		}
	}
}

void remain_smell() {
	for (int s = 1; s <= M; s++) {
		if (shark[s].dead) continue;

		int x = shark[s].x;
		int y = shark[s].y;

		if (board[x][y].id !=s && board[x][y].smell > 0) {
			shark[s].dead = true;
			remainShark--;
		}
		else {
			board[x][y].id = s;
			board[x][y].smell = K;
		}
	}
}
