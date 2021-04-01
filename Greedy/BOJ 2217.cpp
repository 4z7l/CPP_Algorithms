#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> rope(n);
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end());

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (res < rope[i] * (n - i)) {
			res = rope[i] * (n - i);
		}
	}
	cout << res;

	return 0;
}