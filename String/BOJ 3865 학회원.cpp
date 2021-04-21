#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

#define MAX 1010

using namespace std;

void solve(int n) {
	int ind = 0;
	map<string, int> indexMap;
	vector<int> graph[MAX];
	vector<bool> isGroup(MAX, false), visit(MAX, false), isLeafNode(MAX, false);

	string str, key = "";

	for (int i = 0; i < n; i++) {
		cin >> str;
		int groupId = 0;

		// 1. 파싱
		for (int s = 0; s < str.size(); s++) {
			if (str[s] == ':') {
				if (indexMap.find(key) == indexMap.end()) indexMap[key] = ind++;
				int value = indexMap[key];
				isGroup[value] = true;
				groupId = value;
				key = "";
			}
			else if (str[s] == ',' || str[s] == '.') {
				if (indexMap.find(key) == indexMap.end()) indexMap[key] = ind++;
				//그래프 구성
				int value = indexMap[key];
				graph[groupId].push_back(value);
				key = "";
			}
			else {
				key.push_back(str[s]);
			}
		}
	}

	// 2. leaf node인것들
	queue<int> Q;
	Q.push(0);
	visit[0] = true;

	while (!Q.empty()) {
		int next = Q.front();
		Q.pop();

		if (graph[next].size() == 0) { isLeafNode[next] = true; }
		else {
			for (int v : graph[next]) {
				if (!visit[v]) {
					Q.push(v);
					visit[v] = true;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 1010; i++) {
		if (isLeafNode[i] && !isGroup[i]) cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		solve(n);
	}

	return 0;
}

