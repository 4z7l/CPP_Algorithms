#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int start = n % 2 == 0 ? (n / 2) : (n / 2 + 1);
	int cnt = 0;

	int sum=0, i,j;
	while (start>1) {
		sum = 0;
		for (i = start; i >= 1; i--) {
			sum += i;
			if (sum == n) {
				for (j = i; j < start; j++) {
					printf("%d + ", j);
				}
				printf("%d = %d\n", start, n);
				cnt++;
				break;
			}
			if (sum > n) break;
		}
		start--;
	}
	
	printf("%d", cnt);

	return 0;
}
