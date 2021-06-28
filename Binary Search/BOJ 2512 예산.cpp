#include <iostream>

using namespace std;

int yesan[10000];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, sum=0, max=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> yesan[i];
		sum += yesan[i];
		if (max < yesan[i]) max = yesan[i];
	}
	int M;
	cin >> M;
	
	if (M >= sum) {
		cout << max << '\n';
		return 0;
	}

	int left = 1, right = max, mid, res=0, minres=M;
	while (left <= right) {
		mid = (left + right) / 2;
		int temp = M;
		for (int i = 0; i < N; i++) {
			if (mid > yesan[i]) temp -= yesan[i];
			else temp -= mid;
			if (temp < 0) break;
		}
		if (temp < 0) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if (minres > temp) {
				minres = temp;
				res = mid;
			}
		}
	}

	cout << res;
	return 0;
}