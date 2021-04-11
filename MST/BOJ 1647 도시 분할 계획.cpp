#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//6:27PM ~ 6:38PM

struct edge {
	int v, w;
	bool operator<(const edge& e)const {
		return w > e.w;
	}
};

vector<edge> graph[100'001];
vector<bool> visit(100'001, false);

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int sum = 0, max_edge=0;
	priority_queue<edge> pQ;
	pQ.push({ 1,0 });

	while (!pQ.empty()) {
		a = pQ.top().v;
		b = pQ.top().w;
		pQ.pop();

		if (visit[a]) continue;
		visit[a] = true;
		max_edge = max(max_edge, b);
		sum += b;

		for (edge e : graph[a]) {
			if (!visit[e.v]) {
				pQ.push({ e.v, e.w });
			}
		}
	}

	cout << sum- max_edge;

	return 0;
}
