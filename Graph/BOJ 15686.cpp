#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n, m, res=INT_MAX;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int remainChickens[13];

void dfs(int remain, int ch) {
	if (remain == m) {
		int sum = 0, x1, y1, x2, y2;
		
		//치킨 거리 구하고 최솟값 찾기
		for (int i = 0; i < houses.size(); i++) {
			int temp= INT_MAX;
			x1 = houses[i].first;
			y1 = houses[i].second;
			for (int j = 0; j < remain; j++) {
				x2 = chickens[remainChickens[j]].first;
				y2 = chickens[remainChickens[j]].second;
				temp = min(temp, abs(x1 - x2) + abs(y1 - y2));
			}
			sum += temp;
		}
		if (res > sum) res = sum;
	}
	else {
		for (int i = ch; i < chickens.size(); i++) {
			remainChickens[remain] = i;
			dfs(remain + 1, i+1);
		}
	}
}

int main() {
	/*
	* POINT
	* 1. 치킨집과 가정집만 비교해야하니까 각각의 배열을 따로 만들기
	* 2. 폐업할 치킨집 선택(Combination) 후 치킨거리 구하기
	* 3. 최솟값 찾기
	*/

	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int input;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			switch (input) {
			case 1: houses.push_back({ i,j }); break;
			case 2: chickens.push_back({ i,j }); break;
			default: break;
			}
		}
	}

	dfs(0,0);

	cout << res;

	return 0;
}