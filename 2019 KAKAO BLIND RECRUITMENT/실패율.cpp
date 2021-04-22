#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fail {
    double proportion;
    int stageNumber;
    bool operator<(const fail& f)const {
        if (proportion == f.proportion) return stageNumber < f.stageNumber;
        else return proportion > f.proportion;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> stage_user(N + 2, 0);
    vector<int> total_stage_user(N + 2, 0);

    for (int s : stages) {
        stage_user[s]++;
        for (int i = 1; i <= s; i++)
            total_stage_user[i]++;
    }

    vector<fail> failure;
    for (int i = 1; i <= N; i++) {
        if (total_stage_user[i] == 0) failure.push_back({ 0.0,i });
        else failure.push_back({ 1.0 * stage_user[i] / total_stage_user[i],i });
    }
    sort(failure.begin(), failure.end());

    vector<int> answer;
    for (fail f : failure) {
        answer.push_back(f.stageNumber);
    }

    return answer;
}