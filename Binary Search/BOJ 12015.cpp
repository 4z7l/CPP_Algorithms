#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;
    v.push_back(0);
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (v.back() < input) {
            v.push_back(input);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), input);
            *it = input;
        }
    }

    cout << v.size() - 1;

    return 0;
}