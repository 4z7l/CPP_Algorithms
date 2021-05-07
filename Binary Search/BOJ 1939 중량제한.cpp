#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

/*
* BFS/DFS도 이분탐색 쓸수있구나..
*/

struct edge { int v, w; };
vector<edge> graph[10001];

int N, M;
int x, y;
bool visit[10001] = {false,};

bool bfs(int mid) {
	memset(visit, false, sizeof(visit));
	queue<edge> Q;
	Q.push({ x, 0 });
	visit[x] = true;

	while (!Q.empty()) {
		int v = Q.front().v;
		int w = Q.front().w;
		Q.pop();

		if (v == y) return true;

		for (edge e : graph[v]) {
			if (!visit[e.v] && mid <= e.w) {
				Q.push(e);
				visit[e.v] = true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> N >> M;

	int a, b, c;
	int maxCost = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		maxCost = max(maxCost, c);
	}
	cin >> x >> y;

	int lt=0, rt=maxCost, mid;
	int res=0;
	
	while (lt <= rt) {
		mid = (lt + rt) / 2;

		bool ret = bfs(mid);
		if (ret) {
			res = mid;
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}

	cout << res;

	return 0;
}