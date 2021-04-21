#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
* LCS (���� �� �����ϴ� �κ� ����)
* 
* lower_bound : ã������ key���� ���� �ֵ� �� �� ū ��
* upper_bound : ã������ key�� �ʰ��ϴ� ù��° ����
* 
* ������ : lcs �迭�� �����Ѱ� �״�� ����Ѵٰ� �Ǵ°� �ƴ�. ������ index�� �������ְ� �����ؾ���
* 
* ����
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