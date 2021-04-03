#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct edge {
	int v, w;
	bool operator <(const edge& e) const {
		return w > e.w;
	}
};

vector<edge> graph[10000];
vector<bool> isVisited(10000, false);

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int v, e, a, b, c;
	cin >> v >> e;

	//ÇÁ¸²
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	priority_queue<edge> pQ;
	int MST = 0;

	for (edge ed : graph[1]) {
		pQ.push(ed);
	}
	isVisited[1] = true;

	while (!pQ.empty()) {
		edge e = pQ.top();
		pQ.pop();

		if (!isVisited[e.v]) {
			isVisited[e.v] = true;
			MST += e.w;
			for (edge ed : graph[e.v]) {
				pQ.push(ed);
			}
		}
	}

	cout << MST;


	return 0;
}