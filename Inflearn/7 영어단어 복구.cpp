#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);

	string str, out="";
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			out += str[i];
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {
			out += str[i] - 'A' + 'a';
		}
		else {

		}
	}
	cout << out;


	return 0;
}