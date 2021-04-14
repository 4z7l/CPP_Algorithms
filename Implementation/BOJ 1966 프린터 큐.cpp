#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct paper {
	int id;
	int priority;
};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int t, n, m, p, id;
	cin >> t;

	while (t > 0) {
		cin >> n >> m;

		queue<paper> Q;
		for (int i = 0; i < n; i++) {
			cin >> p;
			Q.push({ i,p });
		}

		int cnt = 1;
		while (!Q.empty()) {
			id = Q.front().id;
			p = Q.front().priority;
			Q.pop();

			bool canPrint = true;
			for (int i = 0; i < Q.size(); i++) {
				Q.push(Q.front());
				Q.pop();
				if (p < Q.front().priority)  canPrint = false;
			}
			if (canPrint) {
				if (id == m) {
					cout << cnt << '\n';
					break;
				}
				cnt++;
			}
			else {
				Q.push({ id,p });
			}
		}
		t--;
	}

	return 0;
}
