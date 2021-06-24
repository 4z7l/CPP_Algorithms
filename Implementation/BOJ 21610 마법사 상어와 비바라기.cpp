#include <iostream>
#include <vector>
#include <string.h>

#define x first
#define y second

using namespace std;

int N, M;
int board[50][50];
bool visit[50][50] = { false, };

//  ¡ç, ¢Ø, ¡è, ¢Ö, ¡æ, ¢Ù, ¡é, ¢× 
int dx[9] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };

vector<pair<int, int>> cloud = { { N - 2,0 }, {N - 2,1}, {N - 1,0}, {N - 1,1} };

void move_cloud(int d, int s);
void copy_water();
void evaporate_water();
void print();
int get_sum();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	int d, s;
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		memset(visit, false, sizeof(visit));
		move_cloud(d, s);
		copy_water();
		evaporate_water();
	}

	cout << get_sum();

	return 0;
}

void move_cloud(int d, int s) {
	s %= N;
	for (int i = 0; i < cloud.size(); i++) {
		cloud[i].x = (cloud[i].x + 50 * N + dx[d] * s) % N;
		cloud[i].y = (cloud[i].y + 50 * N + dy[d] * s) % N;
		board[cloud[i].x][cloud[i].y]++;
		visit[cloud[i].x][cloud[i].y] = true;
	}
}

void copy_water() {
	int nx, ny;
	for (int i = 0; i < cloud.size(); i++) {
		for (int d = 2; d <= 8; d += 2) {
			nx = cloud[i].x + dx[d];
			ny = cloud[i].y + dy[d];
			if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
			if (board[nx][ny] > 0) {
				board[cloud[i].x][cloud[i].y]++;
			}
		}
	}
}

void evaporate_water() {
	cloud.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] >= 2 && !visit[i][j]) {
				cloud.push_back({ i,j });
				board[i][j] -= 2;
			}
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int get_sum() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}