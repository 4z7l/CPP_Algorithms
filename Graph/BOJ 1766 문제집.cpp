#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//2:40PM ~ 2:52PM

vector<int> graph[32'001];
int degree[32'001] = {0,};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, a,b;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	priority_queue<int> pQ;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			pQ.push(-i);
		}
	}

	int v;
	while (!pQ.empty()) {
		v = -pQ.top();
		pQ.pop();

		cout << v << ' ';

		for (int w : graph[v]) {
			if (degree[w]>0) {
				degree[w]--;
				if(degree[w]==0)
					pQ.push(-w);
			}
		}
	}

	return 0;
}
