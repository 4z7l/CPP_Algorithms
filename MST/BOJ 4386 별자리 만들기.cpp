#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool visit[100];
vector<pair<float, float>> star;

struct edge {
	int ind;
	float dist;
	bool operator<(const edge& e) const {
		return dist > e.dist;
	}
};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	float a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		star.push_back({ a,b });
	}

	float sum = 0;

	priority_queue<edge> pQ;
	pQ.push({ 0,0.0f });
	

	while (!pQ.empty()) {
		int ind = pQ.top().ind;
		float dist = pQ.top().dist;
		pQ.pop();
		
		if (!visit[ind]) {
			visit[ind] = true;
			sum += dist;
		}
		else continue;

		float x1 = star[ind].first;
		float y1 = star[ind].second;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				float x2 = star[i].first;
				float y2 = star[i].second;
				float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
				pQ.push({ i,d });
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << sum;

	return 0;
}