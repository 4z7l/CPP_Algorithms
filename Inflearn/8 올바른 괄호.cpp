#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

	string str;
	cin >> str;

	int cnt = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')cnt++;
		else cnt--;

		if (cnt < 0) {
			printf("NO\n");
			return 0;
		}
	}
	if (cnt == 0) printf("YES\n");
	else printf("NO\n");

	return 0;
}