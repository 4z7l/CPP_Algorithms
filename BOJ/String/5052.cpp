#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<string> phone(n);
		bool isConsistent = true;
		for (int j = 0; j < n; j++) {
			cin >> phone[j];
		}
		sort(phone.begin(), phone.end());

		for (int j = 1; j < n; j++) {
			if (phone[j-1] == phone[j].substr(0, phone[j-1].length())) {
				isConsistent = false;
				break;
			}
		}
		if (isConsistent) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}