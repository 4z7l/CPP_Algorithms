#include <iostream>
#include <string>
#include <vector>

/**
* 벨만-포드 알고리즘
* - 한 정점에서 다른 정점까지의 최단거리 구할 수 있음
* - 음의 사이클 판별 가능
* - 어느 정점에서 시작해도 음의 사이클 판별할 수 있음 (대신 INF일때 넘어가면 안됨)
* - MAX 값을 잘 정해야함. 무턱대고 INT_MAX로 설정하지 말기
*/

#define MAX 30'000'000

using namespace std;

int n, m, w;

struct edge {
	int s, e, t;
};

bool time_travel(int n, vector<edge> edges) {
	vector<int> dist(n + 1, MAX);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	int s, e, t;
	while (TC > 0) {
		cin >> n >> m >> w;

		vector<edge> edges;

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (time_travel(n, edges)) cout << "YES\n";
		else cout << "NO\n";

		TC--;
	}

	return 0;
}
