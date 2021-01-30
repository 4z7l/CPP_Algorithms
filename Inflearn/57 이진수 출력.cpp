#include <stdio.h>
#include <vector>

using namespace std;

void binary(int n) {
	if (n <= 0) return;
	binary(n/2);
	printf("%d", n%2);
}

int main() {
	int n;
	scanf("%d", &n);
	binary(n);
	return 0;
}
