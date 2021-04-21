#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
* LCS (가장 긴 증가하는 부분 수열)
* 
* lower_bound : 찾으려는 key보다 작은 애들 중 젤 큰 거
* upper_bound : 찾으려는 key를 초과하는 첫번째 원소
* 
* 역추적 : lcs 배열에 저장한거 그대로 출력한다고 되는거 아님. 각각의 index를 저장해주고 추적해야함
* 
* 참고
* https://jaimemin.tistory.com/1095
* https://www.crocus.co.kr/681
* https://www.crocus.co.kr/962
* 
*/


int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	int input;
	vector<int> lis;
	vector<pair<int, int> > lis_ind;

	for (int i = 0; i < n; i++) {
		cin >> input;
		int ind;
		if (lis.empty() || lis.back() < input) {
			ind = lis.size();
			lis.push_back(input);
		}
		else {
			ind = lower_bound(lis.begin(), lis.end(), input) - lis.begin();
			lis[ind] = input;
		}
		lis_ind.push_back({ ind,input });
	}

	vector<int> res;
	int lis_len = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (lis_len == lis_ind[i].first) {
			lis_len--;
			res.push_back(lis_ind[i].second);
		}
	}

	cout << res.size() << '\n';
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << ' ';
	}

	return 0;
}