#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 7:34 ~ 7:52

int N, M, K;
int cost[10'001],unf[10'001];

int Find(int a) {
	if (unf[a] == a) return a;
	else return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;

	if (cost[a] > cost[b]) unf[a] = b;
	else unf[b] = a;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		unf[i] = i;
	}

	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (Find(i) == i) {
			sum += cost[i];
		}
	}
	if (sum > K)cout << "Oh no\n";
	else cout << sum;

	return 0;
}
