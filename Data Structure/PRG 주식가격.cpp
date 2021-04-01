#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int ind = 0, j;

    for (int i = 0; i < prices.size(); i++) {
        for (j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                break;
            }
        }
        if (j == prices.size()) j--;
        answer.push_back(j - i);
    }

    return answer;
}

int main() {
    vector<int> prices,answers;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);

    answers=solution(prices);
    for (int i = 0; i < answers.size(); i++)
        cout << answers[i];

    return 0;
}