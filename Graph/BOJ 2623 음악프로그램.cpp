#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int degree[1001] = {0,};
vector<int> edge[1001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;

	int a,b=0,c=0;
	for (int i = 0; i < M; i++) {
		cin >> a;
		b = 0;
		for (int j = 0; j < a; j++) {
			cin >> c;
			if (b != 0) { edge[b].push_back(c); degree[c]++; }
			b = c;
		}
	}

	queue<int> Q;
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) Q.push(i);
	}

	while (!Q.empty()) {
		int v = Q.front();
		res.push_back(v);
		Q.pop();

		for (int w : edge[v]) {
			degree[w]--;
			if (degree[w] == 0) {
				Q.push(w);
			}
		}
	}

	if (res.size() == N) {
		for (int v : res) {
			cout << v << '\n';
		}
	}
	else cout << 0 << '\n';
	return 0;
}