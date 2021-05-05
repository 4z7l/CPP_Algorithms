#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int pop_doll(vector<vector<int>>& board, int move){
    int doll_id;
    int N = board.size();
    
    int x = 0, y = move-1;
    while(x<N && board[x][y]==0) x++;
    if(x==N) return 0;
    
    doll_id = board[x][y];
    board[x][y] = 0;
    
    return doll_id;
}

bool push_stack(int doll_id, stack<int>& s){
    if(!s.empty() && s.top()==doll_id){
        s.pop();
        return true;
    }
    else {
        s.push(doll_id);
        return false;
    }   
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int move : moves){
        int doll_id =  pop_doll(board, move);
        if(doll_id==0) continue; 
        int ret = push_stack(doll_id, s);
        if(ret) answer+=2;
    }
    
    return answer;
}