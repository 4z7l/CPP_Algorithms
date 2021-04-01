#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) (a>b?a:b)

int graph[10003] = { 0 };
int dp[10003] = { 0 };
int n;

int main() { 
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

    cin >> n;

    for (int i = 3; i < n + 3; i++) {
        cin >> graph[i];
    }

    for (int i = 3; i < n + 3; i++) {
        dp[i] = MAX(dp[i - 2] + graph[i], dp[i - 3] + graph[i - 1] + graph[i]);
        dp[i] = MAX(dp[i - 1], dp[i]);
    }

    cout << dp[n+2];
    
    return 0;
}