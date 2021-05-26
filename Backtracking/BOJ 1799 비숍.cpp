#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 10*10을 두개로 쪼개서 5*5를 두번 수행
 * -> 서로 영향 주지 않는 것들은 따로 수행하기!
 * 테케 쉽게 생성할수있다면 돌려보기..
 */

int N;
bool chess[10][10];
bool check1[20] = { false, };
bool check2[20] = { false, };

void backtracking(int v, int w, int& res) {
	if (v >= 2 * N - 1) {
		res = max(res, w);
		return;
	}

	// 현재에 체스 안놓고 가는 경우
	backtracking(v + 2, w, res);

	// 현재에 체스 놓고 가는 경우
	for (int x = 0; x < N; x++) {
		int y = v - x;
		if (y<0 || y>N - 1) continue;
		if (chess[x][y] && !check1[x + y] && !check2[x - y + N - 1]) {
			check1[x + y] = true;
			check2[x - y + N - 1] = true;
			backtracking(v + 2, w + 1, res);
			check1[x + y] = false;
			check2[x - y + N - 1] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> chess[i][j];
		}
	}

	int res1 = 0, res2 = 0;
	backtracking(0, 0, res1);
	backtracking(1, 0, res2);

	cout << res1 + res2;

	return 0;
}