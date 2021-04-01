#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[1001];

struct edge {
    int start, end, weight;
    bool operator<(const edge& e) const {
        return weight < e.weight;
    }
};

int Find(int x) {
    if (arr[x] == x) return x;
    else Find(arr[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    arr[y] = x;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, m, a, b, c;
    cin >> n >> m;

    vector<edge> graph;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph.push_back({ a,b,c });
    }
    sort(graph.begin(), graph.end());

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < graph.size(); i++) {
        a = graph[i].start;
        b = graph[i].end;
        c = graph[i].weight;

        if (Find(a) != Find(b)) {
            Union(a, b);
            sum += c;
        }
    }

    cout << sum;

    return 0;
}