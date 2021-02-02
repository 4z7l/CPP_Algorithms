#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> students(n + 1);
    vector<vector<bool>> adjacent_matrix(n + 1, vector<bool>(n+1, false));

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adjacent_matrix[a][b] = true;
        adjacent_matrix[b][a] = true;
    }

    scanf("%d %d", &a, &b);

    //bfs
    queue<int> q;
    vector<bool> isVisited(n + 1, false);

    int v = a, w;
    isVisited[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (v == b) {
            printf("YES\n");
            return 0;
        }

        for (int i = 1; i <= n;i++){
            if (!adjacent_matrix[v][i]) continue;
            if (!isVisited[i]) {
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
    printf("NO\n");

    return 0;
}