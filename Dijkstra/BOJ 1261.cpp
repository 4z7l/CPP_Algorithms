#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
int miro[101][101];
int dist[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct edge {
    int x, y, dist;
    edge(int a, int b, int c) : x(a),y(b), dist(c){}
    bool operator<(const edge& e) const {
        return dist > e.dist;
    }
};

int main()
{
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &miro[i][j]);
            dist[i][j] = INT_MAX;
        }
    }

    priority_queue<edge> pQ;
    pQ.push({ 1,1,0 });
    dist[1][1] = 0;

    int x, y, w , nx, ny;
    while (!pQ.empty()) {
        x = pQ.top().x;
        y = pQ.top().y;
        w = pQ.top().dist;
        pQ.pop();

        if (w > dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (dist[nx][ny] > dist[x][y] + miro[nx][ny]) {
                dist[nx][ny] = dist[x][y] + miro[nx][ny];
                pQ.push({ nx,ny, dist[nx][ny] });
            }
        }
    }

    printf("%d", dist[n][m]);

    return 0;
}