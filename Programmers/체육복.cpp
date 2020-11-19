#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    int* students = new int[n + 2];

    for (int i = 0; i < n + 2; i++) {
        students[i] = 1;
    }

    for (int i : lost) students[i]--;
    for (int i : reserve) students[i]++;

    for (int i = 1; i <= n; i++) {
        if (students[i] < 1) {
            if (students[i - 1] > 1) {
                students[i - 1]--;
                students[i]++;
            }
            else if (students[i + 1] > 1) {
                students[i + 1]--;
                students[i]++;
            }
            else { }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (students[i] >= 1) {
            answer++;
        }
    }

    return answer;
}


int main() {
    int n = 5;
    vector<int> lost, reserve;

    lost.push_back(2);
    lost.push_back(4);

    reserve.push_back(1);
    reserve.push_back(3);
    reserve.push_back(5);

    cout << solution(n, lost, reserve);

    return 0;
}
