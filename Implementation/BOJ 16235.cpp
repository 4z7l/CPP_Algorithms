#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct tree {
	int x, y, age;
};

int N, M, K;
int A[11][11], ground[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> trees[11][11];
queue<tree> deadTrees;

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			ground[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}
}

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (trees[i][j].empty()) continue;

			sort(trees[i][j].begin(), trees[i][j].end());

			int t = 0;
			for (t = 0; t < trees[i][j].size();t++) {
				if (ground[i][j] >= trees[i][j][t]) {
					ground[i][j] -= trees[i][j][t];
					trees[i][j][t]++;
				}
				else break;
			}
			while (trees[i][j].size() != t) {
				deadTrees.push({ i,j,trees[i][j].back() });
				trees[i][j].pop_back();
			}
		}
	}
}

void summer() {
	int x, y, age;
	while (!deadTrees.empty()) {
		x = deadTrees.front().x;
		y = deadTrees.front().y;
		age = deadTrees.front().age;
		ground[x][y] += age / 2;
		deadTrees.pop();
	}
}

void fall() {
	int x, y, nx,ny,age;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto t = 0; t < trees[i][j].size(); t++) {
				if (trees[i][j][t]%5==0) {
					for (int k = 0; k < 8; k++) {
						nx = i + dx[k];
						ny = j + dy[k];
						if (nx<1 || nx>N || ny<1 || ny>N) continue;
						trees[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

int getAliveTree() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!trees[i][j].empty()) {
				cnt += trees[i][j].size();
			}
		}
	}
	return cnt;
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ground[i][j] += A[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	input();

	for (int i = 1; i <= K; i++) {
		spring();		
		summer();
		fall();		
		winter();		
	}

	cout << getAliveTree() <<'\n';

	return 0;
}