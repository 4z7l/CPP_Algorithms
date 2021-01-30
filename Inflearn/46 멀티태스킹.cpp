#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, blackout, sum=0;	
	scanf("%d", &n);

	vector<int> process(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &process[i]);
		sum += process[i];
	}
	scanf("%d", &blackout);

	if (sum <= blackout) {
		printf("-1");
		return 0;
	}

	int time = 0, pos = 0;
	while (time < blackout) {
		if (process[pos%n] > 0) {
			process[pos % n]--;
			time++;
		}
		else {
			pos++;
			continue;
		}
		pos++;
	}
	while(process[pos % n] <= 0) {
		pos++;
	}
	printf("%d",( pos % n) + 1);

	return 0;
}
