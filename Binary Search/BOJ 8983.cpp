#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sade[100'000];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, l;
	cin >> n >> m >> l;

	for (int i = 0; i < n; i++) {
		cin >> sade[i];
	}
	sort(sade, sade + n);

	int x, y;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int ind = lower_bound(sade, sade + n, x) - sade;
		if (ind > 0 && abs(sade[ind - 1] - x) < abs(sade[ind] - x)) ind--;
		if (abs(sade[ind] - x) + y <= l) cnt++;
	}

	cout << cnt;

	return 0;
}