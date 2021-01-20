#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

	string str;
	int number=0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			number = number * 10 + (str[i] - '0');
		}
	}
	printf("%d\n", number);

	int cnt = 1;
	for (int i = 2; i <= number; i++) {
		if (number % i == 0) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}