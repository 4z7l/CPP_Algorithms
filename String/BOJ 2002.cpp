#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	map<string,int> M;

	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		M.insert({ str,i });
	}

	int rank[1000];	
	for (int i = 0; i < n; i++) {
		cin >> str;
		rank[i] = M[str];
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (rank[i] > rank[j]) {
				cnt++; break;
			}
		}
	}
	cout << cnt;

	return 0;
}