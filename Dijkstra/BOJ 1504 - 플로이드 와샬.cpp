#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 300'000'000

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, E, a, b, c;
	cin >> N >> E;

	vector<vector<int> > dist(N + 1, vector<int>(N + 1, MAX));
	for (int i = 1; i <= N; i++) dist[i][i] = 0;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	cin >> a >> b;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int x = dist[1][a] + dist[a][b] + dist[b][N];
	int y = dist[1][b] + dist[b][a] + dist[a][N];
	int res = min(x, y);

	if (res >= MAX) cout << -1;
	else cout << res;

	return 0;
}