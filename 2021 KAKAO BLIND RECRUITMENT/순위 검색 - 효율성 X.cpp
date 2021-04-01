#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 1. query 파싱
// 2. 조건 찾기
// 3. 자료구조를 뭘로 선택?

struct employee {
    //언어 직군 경력 소울푸드 점수
    string info[4];
    int score;
    employee(string x[4], int y) {
        for (int i = 0; i < 4; i++) {
            info[i] = x[i];
        }
        score = y;
    }
};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<employee> employees;

    string einfo[4];
    int score;

    // 1. 지원자 정보 등록
    for (int i = 0; i < info.size(); i++) {
        string infoI = info[i];
        for (int j = 0; j < 4; j++) {
            int ind = infoI.find(" ");
            einfo[j] = infoI.substr(0, ind);
            infoI = infoI.substr(ind + 1);
        }
        score = stoi(infoI);
        employees.push_back(employee( einfo, score ));
    }

    for (int i = 0; i < query.size(); i++) {
        // 1. 큐 초기화
        queue<employee> Q;
        for (int j = 0; j < employees.size(); j++) {
            Q.push(employees[j]);
        }

        string queryI = query[i];
        int ind = 0;
        while (queryI != "") {
            int pos = queryI.find(" ");
            string parameter  = queryI.substr(0, pos);

            if (parameter != "-") {
                int qSize = Q.size();
                for (int j = 0; j < qSize; j++) {
                    employee e = Q.front();
                    Q.pop();

                    if (ind < 4 && e.info[ind] == parameter)  Q.push(e);
                    else if (ind == 4 && e.score >= stoi(parameter)) Q.push(e);
                    else continue;
                }
            }

            if (pos == -1) break;

            if (queryI.find("and") != string::npos) queryI = queryI.substr(pos + 5);
            else queryI = queryI.substr(pos + 1);
            ind++;
        }

        answer.push_back(Q.size());
    }

    return answer;
}

int main() {
    vector<int> answer=solution(
        { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" },
        { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}