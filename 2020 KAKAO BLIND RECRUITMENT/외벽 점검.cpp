#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 10000;
	int m = weak.size();

	for (int i = 0; i < m; i++) {
		weak.push_back(weak[i] + n);
	}

	sort(dist.begin(), dist.end());
	do {
		for (int i = 0; i < m; i++) {
			int firstFriend = 0;
			int cover = dist[firstFriend] + weak[i];
			int j;
			for (j = i + 1; j < i + m; j++) {
				if (cover < weak[j]) cover = dist[++firstFriend] + weak[j];
				if (firstFriend == dist.size()) break;
			}
			if (j == i + m) answer = min(answer, firstFriend + 1);
		}
	} while (next_permutation(dist.begin(), dist.end()));

	if (answer == 10000) return -1;

	return answer;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cout << solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 });
	cout << solution(12, { 1,3,4,9,10 }, { 3,5,7 });


	return 0;
}
