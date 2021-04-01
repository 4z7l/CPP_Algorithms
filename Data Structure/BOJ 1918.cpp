#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int getPriority(char opr) {
	if (opr == '*' || opr == '/') return 2;
	if (opr == '+' || opr == '-') return 1;
	if (opr == '(') return 0;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!s.empty() ) {
				if (s.top() == '(') {
					s.pop();
					break;
				}
				cout << s.top();
				s.pop();
			}
		}
		else {
			while (!s.empty() && getPriority(s.top()) >= getPriority(str[i])) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}
