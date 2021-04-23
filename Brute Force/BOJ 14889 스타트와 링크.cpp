#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 9:38~ 10:02

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	int S[21][21] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	vector<int> perm(N),comb(N,0);
	for (int i = 0; i < N; i++) { perm[i] = i+1; }
	for (int i = 0; i < N/2; i++) { comb[i] = 1; }

	int res = 2'147'000'000;

	do {
		int startTeam = 0;
		int linkTeam = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (comb[i] != comb[j]) continue;
				if(comb[i]==1) startTeam += S[perm[i]][perm[j]];
				else linkTeam += S[perm[i]][perm[j]];
			}
		}

		int diff = abs(linkTeam - startTeam);
		res = min(res, diff);

	} while (prev_permutation(comb.begin(), comb.end()));

	cout << res;

	return 0;
}