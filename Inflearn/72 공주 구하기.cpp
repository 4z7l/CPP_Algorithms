#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	int cnt = 0;
	while (q.size() != 1) {
		cnt++;
		if (cnt % k == 0) {
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}

	printf("%d", q.front());

	return 0;
}