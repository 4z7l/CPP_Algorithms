#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

/*
map : 자동으로 사전 순 정렬
map[key]로 value에 접근 가능

입력 개수 모를 때 :  
while (getline(cin,str)){}
do {} while (getc(stdin) == ' ');

cout.precision(n) : 소수점 자릿수 선택
cout<<fixed : 소수점 자리수 고정하겠다는 뜻
*/

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	map<string, int> M;

	string str;
	int n = 0;
	while (getline(cin,str)) {
		M[str]++;
		n++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = M.begin(); it != M.end(); it++) {
		cout << it->first << ' ' << it->second * 100 / (double)n << '\n';
	}

	return 0;
}