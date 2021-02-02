#include <stdio.h>
#include <queue>

using namespace std;

#define SIZE 7

int tree[SIZE + 1] = { 0 };
bool isVisited[SIZE + 1] = { false };

void bfs() {
    queue<int> q;
    int v = 1;

    isVisited[1] = true;
    printf("%d ", 1);

    do {
        for (int i = 0; i < 2; i++) {
            if (v * 2 + i <= SIZE && !isVisited[v * 2 + i]){
                q.push(v * 2 + i);
                isVisited[v * 2 + i] = true;
                printf("%d ", v * 2 + i);

            }
        }

        v = q.front();
        q.pop();
    } while (!q.empty());
}

int main()
{
    int a, b;

    for (int i = 0; i <= SIZE; i++) {
        tree[i] = i;
    }

    bfs();


    return 0;
}
