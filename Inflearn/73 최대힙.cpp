#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> pQ;

	int input;
	while (true) {
		scanf("%d", &input);

		switch (input) {
		case -1:
			return 0;
		case 0:
			if (pQ.empty()) printf("-1\n");
			else {
				printf("%d\n", pQ.top());
				pQ.pop();
			}
			break;
		default:
			pQ.push(input);
			break;

		}
	}

	return 0;
}