#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    int k, n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        n > 0 ? s.push(n) : s.pop();
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}