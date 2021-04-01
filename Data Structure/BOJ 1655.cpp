#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n;

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<>> minHeap;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (maxHeap.size() <= minHeap.size()) maxHeap.push(x);
		else minHeap.push(x);

		if (!maxHeap.empty() && !minHeap.empty()) {
			if (maxHeap.top() > minHeap.top()) {
				int t1 = maxHeap.top();
				int t2 = minHeap.top();

				maxHeap.pop(); minHeap.pop();
				maxHeap.push(t2); minHeap.push(t1);
			}
		}
		cout << maxHeap.top()<<'\n';
	}

	return 0;
}