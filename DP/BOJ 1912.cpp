#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[100'000];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int res = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] = max(arr[i], arr[i-1]+arr[i]);
		res = max(res, arr[i]);
	}

	cout << res;

	return 0;
}