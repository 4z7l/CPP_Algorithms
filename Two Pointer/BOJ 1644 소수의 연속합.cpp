#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> sosu;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		bool isSosu = true;
		for (int j = 2; j*j <=i; j++) {
			if (i % j == 0) {
				isSosu = false;
				break;
			}
		}
		if (isSosu) sosu.push_back(i);
	}

	int res = 0, sum = sosu[0];
	int p1 = 0, p2 = 0;
	while (p1 <= p2 && p1<sosu.size() && p2<sosu.size()) {
		if (sum == N) res++;

		if (sum >= N) sum -= sosu[p1++];
		else sum += sosu[++p2];
	}

	cout << res;

	return 0;
}
