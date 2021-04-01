#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k,w,v;
    cin>>n>>k;
    
    vector<int> dp(k+1,0);
    for(int i=1;i<=n;i++){
        cin>>w>>v;
        for(int j=k;j>=w;j--){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    cout<<dp[k];

    return 0;
}
