#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int vertex;
	int weight;
	Edge(int e, int w) {
		vertex = e;
		weight = w;
	}
	bool operator <(const Edge& e) const {
		return weight > e.weight;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector< pair<int, int> > graph[21];
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}

	vector<int> dist(n + 1, INT_MAX);
	int v = 1, w, cost;

	priority_queue<Edge> pQ;

	dist[v] = 0;
	pQ.push(Edge(1, 0));
	while (!pQ.empty()) {
		v = pQ.top().vertex;
		cost = pQ.top().weight;
		pQ.pop();

		if (cost > dist[v]) continue;

		for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
			w = (*it).first;
			cost = (*it).second;

			if (dist[w] > dist[v] + cost) {
				dist[w] = dist[v] + cost;
				pQ.push(Edge(w, dist[w]));
			}

		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] != INT_MAX) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}

	return 0;
}
