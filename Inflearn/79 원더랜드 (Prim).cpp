#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class edge {
public:
    int vertex;
    int weight;
    edge(int vertex, int w) {
        this->vertex = vertex;
        this->weight = w;
    }
    bool operator <(const edge& c) const{
        return weight > c.weight;
    }
};

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);

    vector<edge> cities[101];
    vector<bool> isAddedVertex(v + 1, false);
    int a, b, w;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &w);
        cities[a].push_back(edge(b, w));
        cities[b].push_back(edge(a, w));
    }

    /**
     * Prim Algorithm
     * 1. ���� ���� ����
     * 2. �������� ����� ������ �� ���� ������ ����(�ּ� ��)
     * 3. �̹� push�� �����̸� �ѱ��, ������ push
     */
    int minCost = 0;
    priority_queue<edge> pQ;

    pQ.push(edge(1, 0));
    while (!pQ.empty()) {
        edge e = pQ.top();
        pQ.pop();

        if (!isAddedVertex[e.vertex]) {
            isAddedVertex[e.vertex] = true;
            minCost += e.weight;

            for (auto it = cities[e.vertex].begin(); it != cities[e.vertex].end(); it++) {
                pQ.push(*it);
            }
        }
    }

    printf("%d", minCost);

    return 0;
}
