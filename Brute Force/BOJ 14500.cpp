#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

int n, m, res = 0;
int paper[501][501];

pair<int,int> tetromino[5][4] = {
	{{0,0}, {0,1}, {0,2}, {0,3}},	//blue
	{{0,0}, {1,0}, {0,1}, {1,1}},	//yellow
	{{0,0}, {1,0}, {2,0}, {2,1}},	//orange
	{{0,0}, {1,0}, {1,1}, {2,1}},	//green	
	{{0,0}, {0,1}, {0,2}, {1,1}}	//pink
};

// ��Ʈ�ι̳븦 ���� ����� �� = ȸ�� 4���� + ��Ī �� ȸ�� 4����
// = 8 -> (x,y ����)*(x�� -����)*(y�� -����) = 2*2*2

// [x][y]�� n��° ��Ʈ�ι̳� ���� ���ϱ�
int place_tetromino(int x, int y, int ind) {
	int sum = 0, ret = 0;
	int nx, ny;

	// 1. �״�� ����
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + tetromino[ind][i].first;
		ny = y + tetromino[ind][i].second;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 2. x�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x - tetromino[ind][i].first;
		ny = y + tetromino[ind][i].second;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 3. y�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + tetromino[ind][i].first;
		ny = y - tetromino[ind][i].second;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 4. x,y �ٲٰ� x�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x - tetromino[ind][i].second;
		ny = y + tetromino[ind][i].first;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 5. x,y �ٲٰ� y�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + tetromino[ind][i].second;
		ny = y - tetromino[ind][i].first;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 6. x,y �ٲٰ� x,y�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x - tetromino[ind][i].second;
		ny = y - tetromino[ind][i].first;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 7. x,y�� - ���̱�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x - tetromino[ind][i].first;
		ny = y - tetromino[ind][i].second;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	// 8. x,y �ٲٱ�
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + tetromino[ind][i].second;
		ny = y + tetromino[ind][i].first;

		if (nx<0 || nx>n || ny<0 || ny>m) {
			sum = 0; break;
		}
		else sum += paper[nx][ny];
	}
	ret = max(ret, sum);

	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 5; k++) {
				int ret = place_tetromino(i, j, k);
				res = max(res, ret);
			}
		}
	}

	cout << res<<'\n';

	return 0;
}