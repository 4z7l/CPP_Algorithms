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

// 테트로미노를 놓는 경우의 수 = 회전 4방향 + 대칭 후 회전 4방향
// = 8 -> (x,y 스왑)*(x에 -붙임)*(y에 -붙임) = 2*2*2

// [x][y]에 n번째 테트로미노 놓고 구하기
int place_tetromino(int x, int y, int ind) {
	int sum = 0, ret = 0;
	int nx, ny;

	// 1. 그대로 놓기
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

	// 2. x에 - 붙이기
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

	// 3. y에 - 붙이기
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

	// 4. x,y 바꾸고 x에 - 붙이기
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

	// 5. x,y 바꾸고 y에 - 붙이기
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

	// 6. x,y 바꾸고 x,y에 - 붙이기
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

	// 7. x,y에 - 붙이기
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

	// 8. x,y 바꾸기
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