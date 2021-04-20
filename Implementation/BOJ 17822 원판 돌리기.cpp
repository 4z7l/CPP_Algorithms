#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

// 3:28PM ~ 4:20PM

struct pos {
	int x, y;
};

int n, m, t;
int board[51][51] = { 0, };
bool visit[51][51] = { false, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void rotate_circle(int x) {
	int temp = board[x][m];
	for (int i = m; i > 1 ; i--) {
		board[x][i] = board[x][i - 1];
	}
	board[x][1] = temp;
}

void rotate_not_circle(int x) {
	int temp = board[x][1];
	for (int i = 1; i < m; i++) {
		board[x][i] = board[x][i + 1];
	}
	board[x][m] = temp;
}

void rotate(int x, int d, int k) {
	for (int i = 2; i <= n; i++) {
		if (i % x == 0) {
			if (d == 0) for (int j = 0; j < k; j++) rotate_circle(i);
			else for (int j = 0; j < k; j++) rotate_not_circle(i);
		}
	}
}

int get_sum() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}

float get_avg() {
	float sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] > 0) cnt++;
			sum += board[i][j];
		}
	}
	//cout << sum<<'/'<<cnt << '\n';
	return sum / cnt * 1.0;
}

void remove_same() {
	//같은 수 있는지 판별
	memset(visit, false, sizeof(visit));
	bool isSameNumberExist = false;

	queue<pos> Q;	
	int number,x,y,nx,ny;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && board[i][j]!=0) {
				visit[i][j] = true;
				Q.push({ i,j });
				number = board[i][j];

				while (!Q.empty()) {
					x = Q.front().x;
					y = Q.front().y;
					Q.pop();

					for (int d = 0; d < 4; d++) {
						nx = x + dx[d];
						ny = y + dy[d];

						if (nx<1 || nx>n) continue;
						if (ny == 0) ny = m;
						if (ny == m+1) ny = 1;

						if (!visit[nx][ny] && board[nx][ny] == number && board[nx][ny]!=0) {
							visit[nx][ny] = true;
							board[nx][ny] = 0;
							board[i][j] = 0;
							Q.push({ nx,ny });
							isSameNumberExist = true;
						}
					}
				}
			}
		}
	}

	//없다? -> 평균 구하고 지우기
	if (isSameNumberExist) return;

	float avg = get_avg();
	//cout << (float)avg << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] > avg) board[i][j] = board[i][j] - 1;
			else if(0<board[i][j] &&  board[i][j] < avg)  board[i][j] = board[i][j] + 1;
		}
	}

}

void print_board() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout<< board[i][j]<<' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
}


int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int x, d, k;
	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;
		rotate(x, d, k);
		//cout << i << "번쨰 회전후\n";
		//print_board();
		remove_same();
		//cout << i << "번쨰 연산후\n";
		//print_board();
	}

	cout << (int)get_sum();

	return 0;
}