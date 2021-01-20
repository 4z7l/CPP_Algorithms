#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

	int n, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp > 0) {
			cnt++;
			temp /= 10;
		}
	}

	printf("%d\n", cnt);



	return 0;
}