#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	map<int, bool> yose;
	for (int i = 1; i <= n; i++)
		yose.insert(make_pair(i, false));

	int cnt = 0;
	int ind = 1;
	auto it = yose.begin();
	cout << '<';
	while (cnt != n) {
		if (it == yose.end()) it = yose.begin();
		if (it->second == false) {
			if (ind == k) {
				ind = 1;
				it->second = true;
				cout << it->first;
				cnt++;
				if (cnt == n) cout << ">\n";
				else cout << ", ";
			}
			else ind++;
		}
		it++;
	}

	return 0;
}