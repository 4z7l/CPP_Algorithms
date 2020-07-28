#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 2 || n>50) return 0;

	pair<int, int>* people = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> people[i].first >> people[i].second;
	}

	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (people[i].first < people[j].first && people[i].second < people[j].second) {
				cnt++;
			}
		}
		cout << cnt << ' ';
	}
	cout << endl;
	return 0;
}