#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//7:00PM ~ 7:13PM

int unf[500'000];

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m,a,b;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		unf[i] = i;
	}

	int res = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (Find(a) != Find(b)) {
			Union(a, b);
		}
		else {
			if (res == 0) res = i;
		}
	}
	cout << res;

	return 0;
}
