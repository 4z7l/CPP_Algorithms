#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int map[20][20];
int dice[7];

// 1234 �����ϳ�
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void move_dice(int dir) {
	int temp;
	if (dir == 1) {
		//����
		temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if (dir == 2) {
		//����
		temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
	else if (dir == 3) {
		//����
		temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
	else {
		// ����
		temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// �ֻ����� ó�� ���ڴ� 0
	for (int i = 1; i <= 6; i++) {
		dice[i] = 0;
	}

	int cmd, nx, ny;
	for (int i = 0; i < k; i++) {
		cin >> cmd;
		// 1. �ֻ��� ������
		nx = x + dx[cmd - 1];
		ny = y + dy[cmd - 1];
		if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
		move_dice(cmd);
		// 2-1. ĭ�� ���� ���� -> �ֻ����� ���� ���
		if (map[nx][ny] > 0) {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		// 2-2. ĭ�� ���� ����(0) -> �ֻ����� ���� ����
		else {
			map[nx][ny] = dice[6];
		}
		x = nx; y = ny;
		cout << dice[1] << '\n';
	}

	return 0;
}