#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 5:36 ~ 6:11

long long calc(long long a, long long b, char ch) {
	if (ch == '+') return a + b;
	else if (ch == '-') return a - b;
	else return a * b;
}

long long solution(string expression) {
	long long answer = 0;

	// 0. parse string
	string str = "";
	vector<char> oper;
	vector<long long> operand;
	for (int i = 0; i < expression.size(); i++) {
		if ('0' <= expression[i] && expression[i] <= '9') {
			str.push_back(expression[i]);
		}
		else {
			operand.push_back(stoll(str));
			oper.push_back(expression[i]);
			str = "";
		}
	}
	operand.push_back(stoll(str));

	// + - * 
	vector<char> operator_char = { '+', '-', '*' };
	vector<int> priority = { 0,1,2 };
	do {
		vector<long long> copy_operand(operand);
		vector<char> copy_oper(oper);

		for (int p = 0; p < priority.size(); p++) {
			for (int i = 0; i < copy_oper.size(); i++) {
				if (operator_char[priority[p]] == copy_oper[i]) {
					long long res = calc(copy_operand[i], copy_operand[i + 1], copy_oper[i]);
					copy_operand[i] = res;
					copy_operand.erase(copy_operand.begin() + i + 1);
					copy_oper.erase(copy_oper.begin() + i);
					i--;
				}
			}
		}
		answer = max(answer, abs(copy_operand[0]));
	} while (next_permutation(priority.begin(), priority.end()));

	return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);


	cout << solution("100-200*300-500+20") << '\n';
	cout << solution("50*6-3*2") << '\n';
	cout << solution("2-990-5+2") << '\n';


	return 0;
}