#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int r, c, res = 0;
string board[20];
bool isUsed[26] = { false, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void backtracking(int x, int y, int cnt) {
	if (res < cnt) {
		res = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || nx>r - 1 || ny<0 || ny>c - 1) continue;

		if(!isUsed[board[nx][ny]-'A']){
			isUsed[board[nx][ny]-'A'] = true;
			backtracking(nx, ny, cnt + 1);
			isUsed[board[nx][ny]-'A'] = false;
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	isUsed[board[0][0] - 'A'] = true;
	backtracking(0, 0, 1);

	cout << res;
	return 0;
}
