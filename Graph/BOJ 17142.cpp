#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct virus {
    int x, y;
    bool isSelected = false;
};

int n, m, res = INT_MAX, blank_size = 0;
int map[50][50];
int temp[50][50];
int dist[50][50];
vector<virus> viruses;
vector<virus> activated_virus;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void spread_virus() {
    queue<virus> Q;

    // 메모리 복사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = map[i][j];
            dist[i][j] = -1;
        }
    }

    // 0 : 빈칸, 1 : 벽, 2 : 비활성 바이러스, 3 : 활성 바이러스
    for (int i = 0; i < activated_virus.size(); i++) {
        temp[activated_virus[i].x][activated_virus[i].y] = 3;
        dist[activated_virus[i].x][activated_virus[i].y] = 0;
        Q.push(activated_virus[i]);
    }

    int cnt = 0;
    int x, y, nx, ny, ret = 0;
    while (!Q.empty()) {
        x = Q.front().x;
        y = Q.front().y;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || temp[nx][ny] == 1
                || dist[nx][ny] != -1) continue;

            Q.push({ nx,ny,0 });
            dist[nx][ny] = dist[x][y] + 1;

            if (temp[nx][ny] == 0) {
                ret = dist[nx][ny];
                cnt++;
            }
        }
    }

    if (cnt == blank_size) {
        if (res > ret) {
            res = ret;
        }
    }
}


void select_virus(int pos, int v) {
    if (v == m) {
        //바이러스 퍼뜨리기
        activated_virus.clear();
        for (int i = 0; i < viruses.size(); i++) {
            if (viruses[i].isSelected) {
                activated_virus.push_back(viruses[i]);
            }
        }
        spread_virus();
    }
    else {
        for (int i = pos; i < viruses.size(); i++) {
            if (!viruses[i].isSelected) {
                viruses[i].isSelected = true;
                select_virus(i + 1, v + 1);
                viruses[i].isSelected = false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) blank_size++;
            if (map[i][j] == 2) viruses.push_back({ i,j, false });
        }
    }

    // 1. 바이러스 m개 선택
    // 2. 바이러스 퍼뜨리기
    // 3. 최솟값 구하기
    select_virus(0, 0);

    if (res == INT_MAX) cout << -1;
    else cout << res;

    return 0;
}
