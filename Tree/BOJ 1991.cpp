#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, pair<char, char>> M;

void preorder(char node) {
	cout << node;
	if (M[node].first != '.') preorder(M[node].first);
	if (M[node].second != '.') preorder(M[node].second);
}

void inorder(char node) {
	if (M[node].first != '.') inorder(M[node].first);
	cout << node;
	if (M[node].second != '.') inorder(M[node].second);
}

void postorder(char node) {
	if (M[node].first != '.') postorder(M[node].first);
	if (M[node].second != '.') postorder(M[node].second);
	cout << node;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	char a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		M.insert({ a,{b,c} });
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}
