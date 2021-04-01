#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100'001

int dist[MAX] = { 0, };
int cnt[MAX] = { 0, };

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	queue<int> Q;
	Q.push(n);
	dist[n] = 0;
	cnt[n] = 1;

	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();

		for (int i : { x - 1, x + 1, 2 * x }) {
			if (i < 0 || i>MAX-1 || i==n) continue;
			if (dist[i] == 0) {
				dist[i] = dist[x] + 1;
				cnt[i] = cnt[x];
				Q.push(i);
			}
			else if (dist[i] == dist[x] + 1) {
				cnt[i] += cnt[x];
			}
		}
	}

	cout << dist[k] << '\n' << cnt[k];
	return 0;
}