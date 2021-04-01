#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct edge {
    int end;
    int weight;
    edge(int a, int b) {
        end = a;
        weight = b;
    }
    bool operator<(const edge& e)const {
        return weight > e.weight;
    }
};

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    int s, e, w;
    vector<edge> graph[1001];
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        graph[s].push_back(edge(e, w));
    }

    vector<vector<int> > dist(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        priority_queue<edge> pQ;
        pQ.push(edge(i, 0));
        dist[i][i] = 0;

        while (!pQ.empty()) {
            e = pQ.top().end;
            w = pQ.top().weight;
            pQ.pop();

            if (w > dist[i][e]) continue;
            
            for (auto it = graph[e].begin(); it != graph[e].end(); it++) {
                int a, b;
                a = (*it).end;
                b = (*it).weight;

                if (dist[i][a] > dist[i][e] + b) {
                    dist[i][a] = dist[i][e] + b;
                    pQ.push(edge(a,dist[i][a]));
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[x][i] + dist[i][x]);
    }
    cout << res;

    return 0;
}