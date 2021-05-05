#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct myset{
    vector<int> elements;
    bool operator<(const myset& m) const{
        return elements.size()< m.elements.size();
    }
};


vector<bool> used(100'001, false);
    
vector<myset> parse_string(string s){
    vector<myset> mysets;
    vector<int> elements;
    string element= "";
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{') continue;
        else if(s[i]=='}'){
            elements.push_back(stoi(element));
            mysets.push_back({elements});
            elements.clear();
            element="";
        }
        else if(s[i]==','){
            if(element.empty()) continue;
            elements.push_back(stoi(element));
            element="";
        }
        else {
            element.push_back(s[i]);
        }
    }
    return mysets;
}

vector<int> solution(string s) {
    vector<myset> mysets = parse_string(s);
    sort(mysets.begin(), mysets.end());
    
    vector<int> answer;
    for(myset m : mysets){
        for(int e : m.elements){
            if(!used[e]) {
                answer.push_back(e);
                used[e] = true;
             }
            else continue;
        }
    }
    
    return answer;
}