#include<iostream>
#include<algorithm>
#include<limits.h>
#include<queue>
#include<vector>

using namespace std;

struct Edge {
	int v, w;
	Edge(int a, int b) {
		v = a; w = b;
	}
	bool operator <(const Edge& e) const {
		return w > e.w;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, start,end, a, b, c;
	cin >> n >> m;

	vector<pair<int, int>>* edges = new vector<pair<int, int>>[n + 1];
	vector<int> dist(n + 1, INT_MAX);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	cin >> start>> end;

	priority_queue<Edge> pQ;
	pQ.push(Edge(start, 0));
	dist[start] = 0;

	int vertex, weight;
	while (!pQ.empty()) {
		vertex = pQ.top().v;
		weight = pQ.top().w;
		pQ.pop();

		if (weight > dist[vertex]) continue;

		for (auto it = edges[vertex].begin(); it != edges[vertex].end(); it++) {
			a = (*it).first;
			b = (*it).second;
			if (dist[a] > dist[vertex] + b) {
				dist[a] = dist[vertex] + b;
				pQ.push(Edge(a, dist[a]));
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}