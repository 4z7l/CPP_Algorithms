#include <stdio.h>
#include <vector>

using namespace std;

int unf[1001];

int Find(int v) {
    if (v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) unf[a] = b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        unf[i] = i;
    }
    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        Union(a, b);
    }

    scanf("%d %d", &a, &b);
    int x = Find(a);
    int y = Find(b);
    if (x != y) printf("NO");
    else printf("YES");

    
    return 0;
}