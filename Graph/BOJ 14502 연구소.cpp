#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, safezone = 0;
int map[10][10];
int temp[10][10];
vector<pair<int, int> > virus;
vector<pair<int, int> > blank;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs() {
    bool isVisited[10][10] = { false, };

    // 1. 벽을 3개 세운 후의 상태 복사
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[i][j] = map[i][j];
        }
    }

    // 2. 바이러스 전파
    int x, y, nx, ny;
    queue<pair<int, int> > Q;

    for (auto it = virus.begin(); it != virus.end(); it++) {
        x = (*it).first;
        y = (*it).second;
        Q.push({ x,y });
        isVisited[x][y] = true;
    }

    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (temp[x][y] == 2 && temp[nx][ny] == 0 && !isVisited[nx][ny]) {
                temp[nx][ny] = 2;
                Q.push({ nx,ny });
                isVisited[nx][ny] = true;
            }
        }
    }

    // 3. 안전 영역 세기
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (temp[i][j] == 0) cnt++;
        }
    }
    if (safezone < cnt) safezone = cnt;

}

void dfs(int wall) {
    if (wall == 3) {
        bfs();
    }
    else {
        int x, y;
        for (auto it = blank.begin(); it != blank.end(); it++) {
            x = (*it).first;
            y = (*it).second;
            if (map[x][y] == 0) {
                map[x][y] = 1;
                dfs(wall + 1);  //벽을 세우고 이동
                map[x][y] = 0;
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) virus.push_back({ i,j });
            else if (map[i][j] == 0) blank.push_back({ i,j });
        }
    }

    dfs(0);

    cout << safezone;

    return 0;
}