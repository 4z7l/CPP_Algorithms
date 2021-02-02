#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    int dist[10001] = { 0 };
    int kongkong[3] = { 1,-1,5 };

    scanf("%d %d", &n, &m);

    //bfs
    queue<int> q;
    int v = n , w;

    q.push(v);
    dist[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            w = v + kongkong[i];
            if (w == m) {
                printf("%d", dist[v]);
                return 0;
            }
            if (dist[w] ==0) {
                q.push(w);
                dist[w] = dist[v] + 1;
            }
        }
    }

    printf("%d", dist[m]);

    return 0;
}
