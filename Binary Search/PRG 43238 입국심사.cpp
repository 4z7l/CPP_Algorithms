#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    int maxTime =0;
    for(int i=0;i<times.size();i++){
        if(maxTime<times[i]) maxTime = times[i];
    }
    
    long long start = 1, end = (long long)maxTime*n, mid;
    long long answer = end;
    while(start<=end){
        mid = (start+end)/2;
        long long cnt=0;
        for(int i=0;i<times.size();i++){
            cnt+= mid/times[i];
        }
        if(cnt<n) start = mid+1;
        else {
            answer = min(answer, mid);
            end = mid-1;
        }
    }
    
    return answer;
}