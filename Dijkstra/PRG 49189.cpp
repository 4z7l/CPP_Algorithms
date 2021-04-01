#include <string>
#include <vector>
#include <queue>

#define MAX 100'000

using namespace std;

vector<int> node[20'001];

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    vector<int> dist(n + 1, MAX);
    dist[1] = 0;
    queue<pair<int, int>> Q;
    Q.push({ 1,0 });
    int v, w;
    while (!Q.empty()) {
        v = Q.front().first;
        w = Q.front().second;
        Q.pop();
        if (dist[v] < w) continue;

        for (int i = 0; i < node[v].size(); i++) {
            if (dist[node[v][i]] > dist[v] + 1) {
                dist[node[v][i]] = dist[v] + 1;
                Q.push({ node[v][i],dist[v] + 1 });
            }
        }
    }

    int max = 0, cnt = 0;
    for (int i = 2; i < n+1; i++) {
        if (max< dist[i]) {
            max = dist[i];
            cnt = 1;
        }
        else if (max == dist[i]) {
            cnt++;
        }
    }

    return cnt;
}