#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int K, N;
	cin >> K >> N;

	vector<long long> lan(K);
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
	}
	sort(lan.begin(), lan.end());

	long long lt = 1, rt = lan[K-1], mid, res=0;
	while (lt <= rt) {
		mid = (lt + rt) / 2;
		
		int count = 0;
		for (int i = 0; i < K; i++) {
			count += lan[i] / mid;
		}
		if (count >= N) {
			res = max(res, mid);
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}
	cout << res;


	return 0;
}