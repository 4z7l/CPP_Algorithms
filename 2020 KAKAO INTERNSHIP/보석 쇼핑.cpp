#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
	set<string> nameSet(gems.begin(), gems.end());
	unordered_map<string, int> countMap;

	int p1 = 0, p2 = 0;
	for (string gem : gems) {
		countMap[gem]++;
		if (nameSet.size() == countMap.size()) break;
		p2++;
	}

	int start = p1, end = p2;

	while (p2 < gems.size()) {
		string key = gems[p1];
		countMap[gems[p1++]]--;

		if (countMap[key] == 0){
			for (p2 = p2 + 1; p2 < gems.size(); p2++) {
				countMap[gems[p2]]++;
				if (key == gems[p2]) break;
			}
			if (end == gems.size()) break;
		}
		if (end - start > p2 - p1) {
			start = p1;
			end = p2;
		}

	}

	return { start + 1, end + 1 };
}

int main() {
	vector<int> res =
		//solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
		//solution({ "AA", "AB", "AC", "AA", "AC" });
	//solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	solution({ "XYZ", "XYZ", "XYZ" });

	cout << res[0] << ' ' << res[1];


	return 0;
}