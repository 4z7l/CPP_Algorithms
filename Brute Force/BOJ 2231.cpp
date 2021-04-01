#include <iostream>	
#include <string>

using namespace std;

int main() {
	int N, tmp = 0, cnt = 0;
	cin >> N;

	tmp = N;
	while (tmp > 0) {
		tmp /= 10;
		cnt++;
	}

	for (int i = N - 9 * cnt; i <= N; i++) {
		tmp = i;
		int sum = tmp;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}