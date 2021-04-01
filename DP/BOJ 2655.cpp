#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct brick {
	int id = 0;
	int area = 0;
	int height = 0;
	int weight = 0;
	brick(int i, int a, int b, int c) {
		id = i;
		area = a;
		height = b;
		weight = c;
	}
	bool operator<(const brick& b)const {
		return area > b.area;
	}
};

struct top {
	int height=0;
	int count=0;
};

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	// 0. 입력
	int n, x, y, z;
	cin >> n;

	vector<brick> bricks;			// : 벽돌의 정보 저장
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		bricks.push_back(brick(i, x, y, z));
	}

	// 1. 밑면에 따라 내림차순
	sort(bricks.begin(), bricks.end());

	// 2. DP
	top dp[100];					// : { 총높이, 사용된개수 }
	int res=0, resId=0;
	int nextBrickId[101] = {0,};	// : 현재 벽돌 위에 쌓인 벽돌의 id 저장

	for (int i = 0; i < n; i++) {
		dp[i].height = bricks[i].height;
		dp[i].count = 1;

		for (int j = 0; j < i; j++) {
			if (bricks[i].weight < bricks[j].weight) {
				if (dp[i].height < dp[j].height + bricks[i].height) {
					dp[i].height = dp[j].height + bricks[i].height;
					dp[i].count = dp[j].count + 1;
					nextBrickId[bricks[i].id] = bricks[j].id;
				}
			}
		}

		if (res < dp[i].height) {
			res = dp[i].height;
			resId = i;
		}
	}

	// 3. 출력
	cout << dp[resId].count << '\n';

	resId = bricks[resId].id;
	while (resId != 0) {
		cout << resId << '\n';
		resId = nextBrickId[resId];
	}

	return 0;
}