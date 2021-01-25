#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> inversion_sequence(n + 1);
	vector<int> original_sequence(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &inversion_sequence[i]);
	}

	int  position;
	for (int i = n; i >= 1; i--) {
		position = i;

		for (int j = 0; j < inversion_sequence[i]; j++) {
			original_sequence[position] = original_sequence[position+ 1];
			position++;
		}
		original_sequence[position] = i;
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", original_sequence[i]);
	}

	return 0;
}
