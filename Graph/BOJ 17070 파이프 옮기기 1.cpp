#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct pipe {
	int tx = 1, ty = 2, dir = 0;
};

int n, cnt=0;
int house[17][17];

vector<int> moveTo[3] = { {0,2},{1,2},{0,1,2} };

vector<pair<int, int>> direction[3] = {
	{{0,1}},
	{{1,0}},
	{{0,1},{1,0},{1,1}}
};

void dfs(pipe p) {
	if (p.tx == n && p.ty == n) {
		cnt++;
		return;
	}

	int nx, ny,d;

	for (int i = 0; i < moveTo[p.dir].size(); i++) {
		for (d = 0; d < direction[moveTo[p.dir][i]].size(); d++) {
			nx = p.tx + direction[moveTo[p.dir][i]][d].first;
			ny = p.ty + direction[moveTo[p.dir][i]][d].second;
			if (nx > n || ny > n || house[nx][ny] == 1) break;
		}
		if (d == direction[moveTo[p.dir][i]].size()) {
			dfs({ nx,ny,moveTo[p.dir][i] });
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> house[i][j];
		}
	}

	pipe p;

	dfs(p);

	cout << cnt;

	return 0;
}