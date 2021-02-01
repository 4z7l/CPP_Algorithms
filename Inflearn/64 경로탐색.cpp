#include <stdio.h>

bool adjacent_matrix[21][21] = {false};
int n, m;
int cnt = 0;
bool isVisited[21] = { false };

void dfs(int pos) {
    if (pos == n) {
        cnt++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (adjacent_matrix[pos][i] && !isVisited[i]) {
                isVisited[i] = true;
                dfs(i);
                isVisited[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adjacent_matrix[a][b] = true;
    }

    isVisited[1] = true;
    dfs(1);

    printf("%d", cnt);

    return 0;
}