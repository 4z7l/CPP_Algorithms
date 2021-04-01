#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;

	while (T.size() > S.size()) {
		if (T[T.size() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	if (S == T) cout << 1;
	else cout << 0;
	return 0;
}