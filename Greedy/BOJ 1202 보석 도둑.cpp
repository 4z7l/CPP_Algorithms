#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int,int> arr[300'000];
int bag[300'000];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);

    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    sort(bag, bag + k);

    priority_queue<int> pQ;
    int ind = 0;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        while (ind < n && arr[ind].first <= bag[i]) {
            pQ.push(arr[ind++].second);
        }
        if (!pQ.empty()) {
            sum += pQ.top();
            pQ.pop();
        }
    }
    cout << sum;

    return 0;
}