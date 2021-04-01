#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

/*
map : �ڵ����� ���� �� ����
map[key]�� value�� ���� ����

�Է� ���� �� �� :  
while (getline(cin,str)){}
do {} while (getc(stdin) == ' ');

cout.precision(n) : �Ҽ��� �ڸ��� ����
cout<<fixed : �Ҽ��� �ڸ��� �����ϰڴٴ� ��
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