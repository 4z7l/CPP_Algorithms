#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compress_string(string s, int n) {
	string new_string = "";
	string pre = "", now = "";
	int cnt = 1;
	for (int i = 0; i < s.length(); i += n) {
		now = s.substr(i, n);
		if (pre == now) {
			cnt++;
		}
		else {
			if (cnt == 1) new_string += pre;
			else new_string += to_string(cnt) + pre;
			pre = now;
			cnt = 1;
		}
	}

	if (cnt == 1) new_string += pre;
	else new_string += to_string(cnt) + pre;

	return new_string.length();
}

int solution(string s) {
	int answer = 1000;
	if (s.size() == 1) return 1;

	// 1 ~ N/2개만 탐색
	//  N/2 개 이상으로 잘랐을 때에는 문자열이 줄지 않음
	for (int i = 1; i <= s.size() / 2; i++) {
		int res = compress_string(s, i);
		if (answer > res)
			answer = res;
	}

	return answer;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string str[] = {
	"a",
	"ababcdcdababcdcd",
	"abcabcdede",
	"abcabcabcabcdededededede",
	"xababcdcdababcdcd"
	};

	for (int i = 0; i < 5; i++) {
		cout << solution(str[i]);
	}

	return 0;
}