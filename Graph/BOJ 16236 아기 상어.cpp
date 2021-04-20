#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int sea[21][21];
bool isVisited[21][21];
int callMomTime = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

struct pos {
	int x, y, dis;
	pos(int a, int b, int c) {
		x = a; y = b; dis = c;
	}
	//최소힙
	bool operator <(const pos& p) const {
		if (dis == p.dis) {
			if (x == p.x) return y > p.y;
			else return x > p.x;
		}
		else return dis > p.dis;
	}
};

struct shark {
	int x;
	int y;
	int size;
	int fishes;
	shark() {
		x = 0; y = 0; size = 2; fishes = 0;
	}
	void ate() {
		fishes++;
		if (fishes == size) {
			size++;
			fishes = 0;
		}
	}
};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	shark babyShark;
	int x = 0, y = 0, dis = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) { babyShark.x = i; babyShark.y = j; }
		}
	}

	//bfs
	priority_queue<pos> pQ;
	pQ.push(pos(babyShark.x, babyShark.y, 0));
	sea[babyShark.x][babyShark.y] = 0;
	isVisited[babyShark.x][babyShark.y] = true;

	int nx, ny;
	while (!pQ.empty()) {
		x = pQ.top().x;
		y = pQ.top().y;
		dis = pQ.top().dis;
		pQ.pop();

		//먹을수있으면 이동후 큐 초기화
		if (0 < sea[x][y] && sea[x][y] < babyShark.size) {
			babyShark.x = x; babyShark.y = y;
			babyShark.ate();
			callMomTime += dis;

			sea[x][y] = 0;
			memset(isVisited, false, sizeof(isVisited));

			priority_queue<pos> emptyQ;
			swap(emptyQ, pQ);
			pQ.push(pos(x, y, 0));
		}
		else {
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx<1 || nx>n || ny<1 || ny>n) continue;
				if (0 <= sea[nx][ny] && sea[nx][ny] <= babyShark.size) {
					if (!isVisited[nx][ny]) {
						isVisited[nx][ny] = true;
						pQ.push(pos(nx, ny, dis + 1));
					}
				}
			}
		}
	}

	cout << callMomTime;

	return 0;
}
