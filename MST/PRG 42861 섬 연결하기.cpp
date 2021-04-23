#include <string>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int v,w;
    bool operator<(const edge& e)const{
        return w>e.w;
    }
};


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<edge> graph[100];
    vector<bool> visit(n, false);
    for(vector<int> c : costs){
        graph[c[0]].push_back({c[1], c[2]});
        graph[c[1]].push_back({c[0], c[2]});
    }
    
    priority_queue<edge> pQ;
    pQ.push({0,0});
    int v,w;
    
    while(!pQ.empty()){
        v = pQ.top().v;
        w = pQ.top().w;
        pQ.pop();
        
        if(visit[v]) continue;
        
        visit[v] = true;
        answer += w;
        for(edge e : graph[v]){
            if(!visit[e.v]){
                pQ.push({e.v, e.w});
            }
        }
    
    }
    
    return answer;
}