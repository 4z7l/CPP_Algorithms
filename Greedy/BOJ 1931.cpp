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

	vector<pair<int, int>> meeting(n);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> meeting[i].second >> meeting[i].first;
	}
	sort(meeting.begin(), meeting.end());

	int res = 0;
	int pre = 0;
	for (int i = 0; i < n; i++) {
		if (meeting[i].second < pre) continue;
		pre = meeting[i].first;
		res++;
	}

	cout << res;

	return 0;
}