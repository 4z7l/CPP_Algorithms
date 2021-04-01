#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> M;
    
    for(int i=0;i<participant.size();i++){
        M[participant[i]]++;
    }
        for(int i=0;i<completion.size();i++){
        M[completion[i]]--;
    }
    
    string answer="";
    for(auto it = M.begin(); it!=M.end();it++){
        if(it->second>0) answer = it->first;
    }
    
    return answer;
}