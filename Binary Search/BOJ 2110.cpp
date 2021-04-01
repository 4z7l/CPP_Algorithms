#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;

    vector<int> wifi(n);
    for (int i = 0; i < n; i++) {
        cin >> wifi[i];
    }
    sort(wifi.begin(), wifi.end());

    int lt = 1, rt = wifi[n - 1], mid, res = 0;

    while (lt <= rt) {
        mid = (lt + rt) / 2;

        int cnt = 1, ind = 0;
        for (int i = 1; i < n; i++) {
            if (wifi[i] - wifi[ind] >= mid) {
                cnt++;
                ind = i;
            }
        }

        if (cnt >= c) {
            lt = mid + 1;
            if (res < mid) res = mid;
        }
        else rt = mid - 1;
    }

    cout << res;

    return 0;
}
