#include <stdio.h>
#include <deque>

using namespace std;

deque<int> dQ[5];
int direction[5];

void rotate_wheels() {
    for (int i = 1; i <= 4; i++) {
        if (direction[i] == -1) {       //반시계
            dQ[i].push_back(dQ[i].front());
            dQ[i].pop_front();
        }
        else if (direction[i] == 1) {   //시계
            dQ[i].push_front(dQ[i].back());
            dQ[i].pop_back();
        }
        else{ }
    }
}

int main() {
    int input;
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &input);
            dQ[i].push_back(input);
        }
    }

    int k;
    scanf("%d", &k);

    int index, dir;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &index, &dir);
        direction[index] = dir;

        int a =  index-1, b=index;
        while (a >=1) {
            if (dQ[a][2] == dQ[b][6]) {
                direction[a] = 0;
            }
            else {
                    direction[a] = -direction[b];
            }
            a--; b--;
        }
        a = index; b = index + 1;
        while (b<=4) {
            if (dQ[a][2] == dQ[b][6]) {
                direction[b] = 0;
            }
            else {
                direction[b] = -direction[a];
            }
            a++; b++;
        }
        rotate_wheels();
    }

    int res = 0;
    if (dQ[1].front() == 1) res += 1;
    if (dQ[2].front() == 1) res += 2;
    if (dQ[3].front() == 1) res += 4;
    if (dQ[4].front() == 1) res += 8;

    printf("%d", res);

    return 0;
}