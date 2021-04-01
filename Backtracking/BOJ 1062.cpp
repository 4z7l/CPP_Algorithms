#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n, k, res = 0;
bool alphabet[26] = { false, };
bool newAlphabet[26] = { false, };
vector<string> words;

void getMax(int level, int teach) {
	if (teach == k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int j = 4;
			for (j = 4; j < words[i].length() - 4; j++) {
				if (!alphabet[words[i][j] - 'a']) break;
			}
			if (j == words[i].length() - 4) cnt++;
		}
		if (res < cnt) res = cnt;
	}
	else {
		for (int i = level; i < 26; i++) {
			if (newAlphabet[i] && !alphabet[i]) {
				alphabet[i] = true;
				getMax(i + 1, teach + 1);
				alphabet[i] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	char antic[] = { 'a', 'n', 't' , 'i' , 'c' };
	for (int i = 0; i < 5; i++) {
		alphabet[antic[i] - 'a'] = true;
	}

	cin >> n >> k;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		words.push_back(str);
	}

	int newWord = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 4; j < words[i].length() - 4; j++) {
			int k = 0;
			for (k = 0; k < 5; k++) {
				if (words[i][j] == antic[k]) break;
			}
			if (k == 5 && !newAlphabet[words[i][j] - 'a']) {
				newAlphabet[words[i][j] - 'a'] = true;
				newWord++;
			}
		}
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}

	if (newWord < k - 5) {
		k = newWord + 5;
	}


	getMax(0, 0);

	cout << res;

	return 0;
}