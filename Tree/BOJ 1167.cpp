#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 100'001

struct node {
	int e;
	int w;
};

vector<node> edges[MAX];
bool isVisited[MAX];

int maxDist = 0, maxNode;

void dfs(int start, int dist) {
	if (maxDist < dist) {
		maxDist = dist;
		maxNode = start;
	}

	for (auto it = edges[start].begin(); it != edges[start].end(); it++) {
		if (!isVisited[it->e]) {
			isVisited[it->e] = true;
			dfs(it->e, dist + it->w);
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int s, e, w;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		do {
			cin >> e;
			if (e == -1) break;
			cin >> w;
			edges[s].push_back({ e,w });
		} while (true);
	}

	memset(isVisited, false, sizeof(isVisited));
	isVisited[1] = true;
	dfs(1, 0);

	memset(isVisited, false, sizeof(isVisited));
	isVisited[maxNode] = true;
	maxDist = 0;
	dfs(maxNode, 0);

	cout << maxDist;

	return 0;
}
