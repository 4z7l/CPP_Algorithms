#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    
    vector<int> dp1(n, 0), dp2(n, 0);
    dp1[0] = money[0]; dp1[1] = money[0];
    dp2[1] = money[1];
    
    for(int i=2;i<=n-2;i++){
        dp1[i] = max(dp1[i-1], dp1[i-2]+money[i]);
    }
    for(int i=2;i<=n-1;i++){
        dp2[i] = max(dp2[i-1], dp2[i-2]+money[i]);
    }
    
    return max(dp1[n-2],dp2[n-1]);
}