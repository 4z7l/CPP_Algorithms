#include <vector>
#include <cstring>
#include <iostream>

#define MAX 100'001

using namespace std;

int students[MAX];
bool visit[MAX], done[MAX];
int cnt;

void dfs(int ind) {
	visit[ind] = true;

	int next = students[ind];
	if (!visit[next]) {
		dfs(next);
	}
	else {
		if (!done[next]) {
			for (int i = next; i != ind; i = students[i]) cnt++;
			cnt++;
		}
	}
	done[ind] = true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> students[i];
		}
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) dfs(i);
		}
		cout << n - cnt << '\n';
		t--;
	}

	return 0;
}