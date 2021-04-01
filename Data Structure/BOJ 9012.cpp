#include <iostream>
#include <stack>

using namespace std;

bool check_VPS(string input) {
    stack<int> s;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            s.push(input[i]);
        }
        else {
            if (s.empty()) return false;
            s.pop();
        }
    }
    if (!s.empty()) return false;
    return true;
}

int main() {
    int k;
    cin >> k;

    string input;
    for (int i = 0; i < k; i++) {
        cin >> input;
        check_VPS(input) ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}