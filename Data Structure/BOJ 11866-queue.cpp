#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	queue<int> yose;

	for (int i = 1; i <= n; i++)
		yose.push(i);

	int cnt = 0;
	int front;
	cout << '<';
	while (!yose.empty()) {
		cnt++;
		if (cnt == k) {
			front = yose.front();
			yose.pop();
			cout << front;
			cnt = 0;
			if (yose.empty()) cout << ">\n";
			else cout << ", ";
		}
		else {
			front = yose.front();
			yose.push(front);
			yose.pop();
		}

	}


	return 0;
}