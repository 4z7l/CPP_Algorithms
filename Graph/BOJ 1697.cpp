#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

bool isVisited[100'000];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> Q;
	Q.push({ n,0 });
	isVisited[n] = true;

	int v,w;
	while (!Q.empty()) {
		v = Q.front().first;
		w = Q.front().second;
		Q.pop();

		if (v == k) {
			cout << w;
			break;
		}

		if (0 <= v + 1 && v + 1 <= 100'000 && !isVisited[v + 1]) {
			isVisited[v + 1] = true;
			Q.push({ v + 1, w + 1 });
		}
		if (0 <= v - 1 && v - 1 <= 100'000 && !isVisited[v - 1]) {
			isVisited[v - 1] = true;
			Q.push({ v - 1, w + 1 });
		}
		if (0 <= 2*v && 2 * v <= 100'000 && !isVisited[2 * v]) {
			isVisited[2 * v] = true;
			Q.push({ 2 * v, w + 1 });
		}
	}

	return 0;
}
