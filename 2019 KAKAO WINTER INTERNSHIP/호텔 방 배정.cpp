#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> M;

long long Find(long long a){
    if(M[a]==0) return a;
    else return M[a] = Find(M[a]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(long long n: room_number){
        if(M[n]==0){
            answer.push_back(n);
            M[n] = Find(n+1);
        }
        else {
            long long next = Find(n);
            answer.push_back(next);
            M[next] = Find(next+1);
        }
    }
    
    return answer;
}