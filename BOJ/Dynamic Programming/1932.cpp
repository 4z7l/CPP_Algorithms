#include <stdio.h>
#include <vector>

using namespace std;

#define MAX(a, b) (a>b?a:b)

int main() { 
    int n;
    scanf("%d", &n);

    vector<vector<int>> triangles, dp;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j <= i; j++) {
            int t;
            scanf("%d", &t);
            v.push_back(t);
        }
        triangles.push_back(v);
    }

    vector<int> v;
    v.push_back(triangles[0][0]);
    dp.push_back(v);

    int sum;
    for (int i = 1; i < n; i++) {
        vector<int> v;
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                sum = dp[i - 1][j] + triangles[i][j];
            }
            else if (j == i) {
                sum = dp[i - 1][j - 1] + triangles[i][j];
            }
            else {
                sum = MAX(dp[i - 1][j - 1], dp[i - 1][j]) + triangles[i][j];
            }

            v.push_back(sum);
        }
        dp.push_back(v);
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < dp[n - 1][i]) {
            max = dp[n - 1][i];
        }
    }

    printf("%d\n", max);
    return 0;
}