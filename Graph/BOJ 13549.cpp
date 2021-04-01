#include <iostream>
#include <queue>
#include <vector>

#define MAX 100'000

using namespace std;

bool isVisited[MAX] = { false, };

struct node {
	int vertex;
	int dist;
	bool operator<(const node& n) const {
		if (dist == n.dist) return vertex > n.vertex;
		else return dist > n.dist;
	}
};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	priority_queue<node> Q;
	Q.push({ n,0 });
	isVisited[n] = true;

	int v, w;
	while (!Q.empty()) {
		v = Q.top().vertex;
		w = Q.top().dist;
		Q.pop();

		if (v == k) {
			cout << w;
			return 0;
		}

		if (0 <= 2 * v && 2 * v <= MAX && !isVisited[2 * v]) {
			isVisited[2 * v] = true;
			Q.push({ 2 * v, w });
		}
		if (0 <= v - 1 && v - 1 <= MAX && !isVisited[v - 1]) {
			isVisited[v - 1] = true;
			Q.push({ v - 1, w + 1 });
		}
		if (0 <= v + 1 && v + 1 <= MAX && !isVisited[v + 1]) {
			isVisited[v + 1] = true;
			Q.push({ v + 1, w + 1 });
		}


	}

	return 0;
}
