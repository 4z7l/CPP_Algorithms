#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
* 참고 : 14003번
*/

int n;
int swtch[10'001], bulb[10'001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	// 1. 입력
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) { cin >> swtch[i]; }
	for (int i = 1; i <= n; i++) { cin >> x; bulb[x] = i; }

	// 2. lcs 구하기
	vector<int> lcs;
	vector<pair<int,int>> lcs_ind;
	int ind;
	for (int i = 1; i <= n; i++) {
		x = bulb[swtch[i]];
		if (lcs.empty() || lcs.back() < x) {
			ind = lcs.size();
			lcs.push_back(x);
		}
		else {
			ind = lower_bound(lcs.begin(), lcs.end(), x) - lcs.begin();
			lcs[ind] = x;
		}
		lcs_ind.push_back({ ind,swtch[i] });
	}

	// 3. 전구 번호 구하기
	vector<int> res;
	int lcs_len = lcs.size() - 1;
	for (int i = lcs_ind.size() - 1; i >= 0; i--) {
		if (lcs_len == lcs_ind[i].first) {
			res.push_back(lcs_ind[i].second);
			lcs_len--;
		}
	}

	// 4. 정렬 후 최종 출력
	sort(res.begin(), res.end());

	cout << lcs.size() << '\n';
	for (int r : res) { cout << r << ' '; }

	return 0;
}