#include <stdio.h>

bool checked[11] = { false };

void dfs(int pos, int n) {
    if (pos > n) {
        for (int i = 1; i <= n; i++) {
            if (checked[i]) printf("%d ", i);
        }
        printf("\n");
        return;
    }

    checked[pos] = true;
    dfs(pos + 1, n);
    checked[pos] = false;
    dfs(pos + 1, n);
}

int main() {
    int n;
    scanf("%d", &n);

    dfs(1, n);

    return 0;
}