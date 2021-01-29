#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	stack<char> bracket;

	char input[30];
	scanf("%s", input);

	for (int i = 0; input[i] != 0; i++) {
		if (input[i] == '(') {
			bracket.push('(');
		}
		else {
			if (bracket.empty()) {
				printf("NO");
				return 0;
			}
			bracket.pop();
		}
	}
	if (bracket.empty()) {
		printf("YES");
	}
	else {
		printf("NO");
	}


	return 0;
}