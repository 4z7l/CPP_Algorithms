#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[102][102] = { 0 };
int region[102][102] = { 0 };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for (auto p : puddles) {
        region[p[1]][p[0]] = -1;
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (region[i][j] == -1) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000007;
        }
    }

    return dp[n][m];
}

int main() {
    cout << solution(4, 3, { {2,2} });
    return 0;
}
