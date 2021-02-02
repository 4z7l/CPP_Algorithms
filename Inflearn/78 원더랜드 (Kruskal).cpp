#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Road {
public:
    int c1;
    int c2;
    int weight;
    Road(int c1, int c2, int w) {
        this->c1 = c1;
        this->c2 = c2;
        this->weight = w;
    }
    const bool operator <(const Road& r) {
        return weight < r.weight;
    }
};

int unf[101];
int cities[101];
vector<Road> road;

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
    int v, e;
    scanf("%d %d", &v, &e);

    // 1. 네트워크 구성
    int a, b, c;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        road.push_back(Road(a,b,c));
    }

    // 2. 간선 정렬
    sort(road.begin(), road.end());

    // 3. 유니온파인드
    for (int i = 1; i <= v; i++) {
        unf[i] = i;
    }

    // 3. 크루스칼 알고리즘 & 유니온파인드 사용
    int result = 0;
    int c1, c2, weight;
    for (int i = 0; i < e; i++) {
        c1 = road[i].c1;
        c2 = road[i].c2;
        weight = road[i].weight;

        // 같은 집합이 아닌경우 : 합치고 간선 추가
        if (Find(c1) != Find(c2)) {
            Union(c1, c2);
            result += weight;
        }

    }

    printf("%d", result);
    
    return 0;
}