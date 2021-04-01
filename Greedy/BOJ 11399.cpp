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

	vector<int> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}
	sort(people.begin(), people.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += people[i] * (n - i);
	}

	cout << sum;

	return 0;
}