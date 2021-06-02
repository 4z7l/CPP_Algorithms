#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int M;
	cin >> M;

	string str;
	int x;

	int S=0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		switch (str[1]) {
		case 'd': 
			cin >> x; 
			S |= 1 << x; 
			break;
		case 'e':
			cin >> x; 
			S &= ~(1 << x); 
			break;
		case 'h': 
			cin >> x;
			if (S & 1 << x)cout << 1 << '\n';
			else cout << 0 << '\n'; 
			break;
		case 'o': 
			cin >> x; 
			S ^= (1 << x);
			break;
		case 'l': S |= ~(0 << 20); break;
		case 'm': S = 0; break;
		}
	}

	return 0;
}