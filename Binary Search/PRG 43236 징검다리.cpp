#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 0, end= rocks[rocks.size()-1], mid;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    while(start<=end){
        mid = (start+end)/2;
        
        int cnt=0, a=0, b=1;
        while(b<rocks.size()){
            if(rocks[b]-rocks[a]<mid) cnt++;
            else a = b;
            b++; 
        }
        
        if(cnt<=n) {
            answer = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    
    return answer;
}