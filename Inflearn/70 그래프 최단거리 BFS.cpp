#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[21];
int dist[21] = { 0 };
bool isVisited[21] = { false };

void bfs() {
    queue<int> q;
    int v = 1;

    q.push(v);
    isVisited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
            if (!isVisited[*it]) {
                isVisited[*it] = true;
                q.push(*it);
                dist[*it] = dist[v] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }

    bfs();

    for (int i = 2; i <= n; i++) {
        printf("%d : %d\n", i, dist[i]);
    }


    return 0;
}
