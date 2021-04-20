#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int N, L, R, res = 0;
int country[50][50];
bool isVisited[50][50] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void clear_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isVisited[i][j] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}

	//BFS
	vector<pair<int, int> > union_country;
	queue<pair<int, int>> Q;
	int x, y, nx, ny, popularity = 0;
	bool isUnionExist = true;
	while (isUnionExist) {
		isUnionExist = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j]) {
					union_country.clear();

					Q.push({ i,j });
					isVisited[i][j] = true;
					popularity = country[i][j];
					union_country.push_back({ i,j });
					while (!Q.empty()) {
						x = Q.front().first;
						y = Q.front().second;
						Q.pop();

						for (int k = 0; k < 4; k++) {
							nx = x + dx[k];
							ny = y + dy[k];
							if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;

							int diff = abs(country[x][y] - country[nx][ny]);
							if (L <= diff && diff <= R && !isVisited[nx][ny]) {
								Q.push({ nx,ny });
								isVisited[nx][ny] = true;
								popularity += country[nx][ny];
								union_country.push_back({ nx,ny });
							}
						}
					}
					if (union_country.size() > 1) {
						isUnionExist = true;
						popularity /= union_country.size();
						for (int k = 0; k < union_country.size(); k++) {
							x = union_country[k].first;
							y = union_country[k].second;
							country[x][y] = popularity;
						}
					}

				}
			}
		}
		if (isUnionExist) {
			res++;
			clear_visited();
		}
	}
	cout << res;

	return 0;
}