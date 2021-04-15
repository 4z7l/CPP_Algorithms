#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct pos {
	int x, y, dir, sum;
	bool operator<(const pos& p)const {
		return sum < p.sum;
	}
};

int solution(vector<vector<int>> board) {
	int answer = INT_MAX;
	int n = board.size();

	vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
	priority_queue<pos> Q;
	Q.push({ 0,0,-1,0 });
	dp[0][0] = 0;

	int x, y, dir, sum;
	while (!Q.empty()) {
		x = Q.top().x;
		y = Q.top().y;
		dir = Q.top().dir;
		sum = Q.top().sum;
		Q.pop();

		if (x == n - 1 && y == n - 1) {
			answer = min(answer, sum);
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx>n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 1) continue;

				int cost;
				if (dir == -1 || dir == i) cost = sum + 100;
				else cost = sum + 600;
				if (dp[nx][ny] >= cost) {
					Q.push({ nx,ny,i,cost });
					dp[nx][ny] = cost;
				}
			}
		}
	}
	return answer;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);


	cout << solution({ {0,0,0},{0,0,0},{0,0,0} }) << '\n';
	cout << solution(
		{ {0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0} }) << '\n';

	cout << solution(
		{ {0, 0, 1, 0},{0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0} }) << '\n';

	cout << solution({ {0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
						{1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
						{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
						{0, 0, 1, 0, 1, 1, 0, 1, 0, 1},
						{0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
						{1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
						{1, 0, 0, 0, 0, 0, 0, 0, 1, 0} }
	) << '\n';
	//cout << res;


	return 0;
}
