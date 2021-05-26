#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 10*10�� �ΰ��� �ɰ��� 5*5�� �ι� ����
 * -> ���� ���� ���� �ʴ� �͵��� ���� �����ϱ�!
 * ���� ���� �����Ҽ��ִٸ� ��������..
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

	// ���翡 ü�� �ȳ��� ���� ���
	backtracking(v + 2, w, res);

	// ���翡 ü�� ���� ���� ���
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