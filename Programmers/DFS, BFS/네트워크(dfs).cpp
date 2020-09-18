#include <string>
#include <vector>

using namespace std;

bool visited[200] = { false };

void dfs(int n, vector<vector<int>> computers, int start) {
    visited[start] = true;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        if (computers[start][i] == 1 && visited[i] == false) {
            dfs(n, computers, i);
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            dfs(n, computers, i);
            answer++;
        }
    }

    return answer;
}