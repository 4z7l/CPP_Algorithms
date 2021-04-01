#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct top {
    int height;
    int id;
    top(int h, int i) {
        height = h;
        id = i;
    }
    bool operator <(const top& t)const {
        return height < t.height;
    }
};

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n;

    stack<top> s;
    vector<int> res(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x;
        res[i] = 0;
        while (!s.empty() && x > s.top().height) s.pop();
        if (!s.empty()) res[i] = s.top().id;
        s.push(top(x, i));
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}