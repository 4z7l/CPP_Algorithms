#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct edge {
	int s, e, w;
};

long long dist[501];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;

	vector<edge> graph;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph.push_back({ a,b,c });
	}

	dist[1] = 0;
	for (int i = 2; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a = graph[j].s;
			b = graph[j].e;
			c = graph[j].w;

			if (dist[a] != INT_MAX && dist[b] > dist[a] + c) {
				dist[b] = dist[a] + c;
			}
		}
	}

	//음의 사이클
	for (int j = 0; j < m; j++) {
		a = graph[j].s;
		b = graph[j].e;
		c = graph[j].w;

		if (dist[a] != INT_MAX && dist[b] > dist[a] + c) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == INT_MAX) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
}
