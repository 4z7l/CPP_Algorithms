#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	int sum = 1, number = 1, share;

	while (sum < n) {
		number++;
		sum += number;
		if ((n - sum) % number == 0) {
			cnt++;
			share = (n - sum) / number;
			for (int i = 1; i < number; i++) {
				printf("%d + ", i + share);
			}
			printf("%d = %d\n", number + share, n);
		}
	}
	
	printf("%d", cnt);

	return 0;
}
