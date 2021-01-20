#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

	int small[26] = {0}, big[26] = { 0 };

	string str1, str2;

	cin >> str1;
	cin >> str2;

	int ind;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z') {
			ind = str1[i] - 'a';
			small[ind]++;
		}
		else {
			ind = str1[i] - 'A';
			big[ind]++;
		}
	}

	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] >= 'a' && str1[i] <= 'z') {
			ind = str2[i] - 'a';
			small[ind]--;
		}
		else {
			ind = str2[i] - 'A';
			big[ind]--;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (small[i] != 0 || big[i] != 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}