#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<bool> prince(n, true);
	int out = 0, ind = -1, cnt = 0;

	while (out < n - 1) {
		ind++;
		if (prince[ind % n] == true) {
			cnt++;
		}

		if (cnt == m) {
			cnt = 0; out++;
			prince[ind % n] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		if (prince[i] == true) {
			printf("%d", i + 1);
			break;
		}
	}

	return 0;
}
