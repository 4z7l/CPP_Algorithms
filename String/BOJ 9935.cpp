#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string str, bomb;
	cin >> str;
	cin >> bomb;

	bool isSame;
	string result="";

	for (int i = 0; i < str.size(); i++) {
		result+=str[i];

		if (result.size() >= bomb.size() && str[i] == bomb[bomb.size() - 1]) {
			isSame = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (result[result.size()-1 - j] != bomb[bomb.size() -1 - j]) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				result.erase(result.size() - bomb.size());
			}
		}
	}

	if (result.size() > 0) cout << result;
	else cout << "FRULA";

	return 0;
}