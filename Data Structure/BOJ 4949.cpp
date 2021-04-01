#include <iostream>
#include <string>
#include <stack>

using namespace std;

void checkString(string input) {
	stack<char> mystack;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(' || input[i] == '[') 
			mystack.push(input[i]);

		if (input[i] == ')') {
			if(!mystack.empty() && mystack.top() == '(') mystack.pop();
			else {
				cout << "no" << '\n';
				return;
			}
		}

		if (input[i] == ']') {
			if (!mystack.empty() && mystack.top() == '[') mystack.pop();
			else {
				cout << "no" << '\n';
				return;
			}
		}
	}

	if(mystack.empty()) cout << "yes" << '\n';
	else cout << "no" << '\n';
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string input;

	while (true) {
		getline(cin, input);
		if (input.compare(".") == 0) break;
		checkString(input);
	}

	return 0;
}