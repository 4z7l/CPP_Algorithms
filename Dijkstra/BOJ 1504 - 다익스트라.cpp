#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 300'000'000

using namespace std;

vector<pair<int, int>> edges[801];
vector<vector<int>> dist(3, vector<int>(801, MAX));

void dijkstra(vector<int>& dist, int start) {
	priority_queue<pair<int, int>> pQ;
	pQ.push({ 0,start });
	dist[start] = 0;

	int v, w;
	while (!pQ.empty()) {
		w = pQ.top().first;
		v = pQ.top().second;
		pQ.pop();

		if (dist[v] > -w) continue;

		for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
			if (dist[it->first] > dist[v] + it->second) {
				dist[it->first] = dist[v] + it->second;
				pQ.push({ -dist[it->first],it->first });
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, E, a, b, c;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	cin >> a >> b;

	dijkstra(dist[0], 1);
	dijkstra(dist[1], a);
	dijkstra(dist[2], b);

	int x = dist[0][a] + dist[1][b] + dist[2][N];
	int y = dist[0][b] + dist[2][a] + dist[1][N];
	int res = min(x, y);

	if (res >= MAX) cout << -1;
	else cout << res;

	return 0;
}