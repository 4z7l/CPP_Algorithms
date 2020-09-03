#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> pQ;
    int cnt = 0, out = 0;
    
    for (int i = 0; i < progresses.size(); i++)
        pQ.push(progresses[i]);

    int speedSize = speeds.size();
    int* cumulateSpeed = new int[speedSize];
    for (int i = 0; i < speedSize; i++)
        cumulateSpeed[i] = 0;

    do {
        if (pQ.front()+ cumulateSpeed[out] >= 100) {
            cnt++; out++;
            pQ.pop();
        }
        else {
            if (cnt > 0) {
                answer.push_back(cnt);
                cnt = 0;
            }
            for (int i = out; i < speedSize; i++) {
                cumulateSpeed[i] += speeds[i];
            }
        }


    } while (!pQ.empty());

    answer.push_back(cnt);
    return answer;
}

int main() {
    vector<int> progresses, speeds, answer;

    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);

    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    /*progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);

    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);*/

    answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}