#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define INF 10'000'000

int dist[101][101];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, m, a,b,c;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) dist[i][j] = 0;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}