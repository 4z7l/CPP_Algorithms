#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	int alphabet[26] = {0};
	int x = 1;
	for (int i = 0; i < n; i++) {
		x = 1;
		while (words[i].size() > 0) {
			char ch = words[i].back();
			alphabet[ch - 'A'] += x;
			x *= 10;
			words[i].pop_back();
		}
	}

	sort(alphabet, alphabet + 26, greater<>());
	x = 9;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0) break;
		sum += alphabet[i] * x;
		x--;
	}
	cout << sum;

	return 0;
}