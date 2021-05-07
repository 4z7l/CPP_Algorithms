#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void get_comb(int ind, vector<string>& user_id, vector<string>& banned_id, vector<int>* same, vector<bool>& used, vector<int> num, set<string>& S){
    if(ind==banned_id.size()){
        sort(num.begin(), num.end());
        string str="";
        for(int n:num){
            str+= to_string(n);
        }
        S.insert(str);
        return;
    }
    for(int j=0;j<same[ind].size();j++){
        if(!used[same[ind][j]]){
            used[same[ind][j]] = true;
            num.push_back(same[ind][j]);
            get_comb(ind+1, user_id, banned_id, same, used, num, S);     
            num.pop_back();
            used[same[ind][j]] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> same[8];
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if(user_id[j].size()!=banned_id[i].size()) continue;
            int sind=0;
            bool flag= true;
            for(int b=0;b<banned_id[i].size();b++){
                if(banned_id[i][b]=='*') {sind++; continue;}
                else if(sind>=user_id[j].size()) {flag = false; break;}
                else if(user_id[j][sind]==banned_id[i][b]) {sind++; continue;}
                else {flag = false; break;}
            }
            if(flag) {
                same[i].push_back(j);
            }
        }
    }
    
    vector<bool> used(8, false);
    vector<int> num;
    set<string> S;
    get_comb(0, user_id, banned_id, same, used, num, S);     

    return S.size();
}