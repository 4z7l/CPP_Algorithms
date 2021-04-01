#include <string>
#include <vector>
#include <queue>

#define MAX 100'000'000

using namespace std;

void dijkstra(vector<pair<int,int>>* edges, vector<int>& dist, int start) {
    priority_queue<pair<int,int>> pQ;
    pQ.push({0, start});
    dist[start] = 0;
    
    int v,w;
    while(!pQ.empty()){
        w = pQ.top().first;
        v = pQ.top().second;
        pQ.pop();
        
        if(dist[v] < -w) continue;
        
        for(auto it = edges[v].begin(); it!=edges[v].end();it++){
            if(dist[it->first] > dist[v] + it->second){
                dist[it->first] = dist[v] + it->second;
                pQ.push({-dist[it->first],it->first});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<pair<int,int>> edges[201];
    for(int i=0;i<fares.size();i++){
        edges[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        edges[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, MAX));
    
    for(int i=1;i<=n;i++){
        dijkstra(edges, dist[i], i);
    }

    int answer = MAX;
    for(int i=1;i<=n;i++){
        if(answer> dist[s][i] + dist[i][a]+ dist[i][b]){
            answer= dist[s][i] + dist[i][a]+ dist[i][b];
        }
    }
    
    return answer;
}