#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;

	queue<int> queue;
	for (int i = 1; i <= n; i++)
		queue.push(i);

	int front;
	while (!queue.empty()) {
		front = queue.front();
		queue.pop();
		if (queue.empty()) break;

		queue.push(queue.front());
		queue.pop();

	}

	cout << front;

	return 0;
}