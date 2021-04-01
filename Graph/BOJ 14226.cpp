#include <iostream>
#include <queue>

using namespace std;

struct emoji{
  int ui, clipboard, time;  
};

bool visit[1001][1001] = {false,};

int main()
{
    int S;
    cin>>S;
    
    queue<emoji> Q;
    Q.push({1,0,0});
    visit[1][0] = true;
    
    int ui,clipboard, time;
    while(!Q.empty()){
        ui = Q.front().ui;
        clipboard = Q.front().clipboard;
        time = Q.front().time;
        Q.pop();
        
        if(ui==S) break;; 
        
        if(!visit[ui][ui]){
            visit[ui][ui] = true;
            Q.push({ui, ui, time+1});
        }
        if(ui+clipboard<=1000 && !visit[ui+clipboard][clipboard]){
            visit[ui+clipboard][clipboard] = true;
            Q.push({ui+clipboard, clipboard, time+1});
        }
        if(ui>1 && !visit[ui-1][clipboard]){
            visit[ui-1][clipboard] = true;
            Q.push({ui-1, clipboard, time+1});
        }
    }
    cout<<time;

    return 0;
}
