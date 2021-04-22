#include <iostream>
#include <string>
#include <vector>

#include <set>
#include <algorithm>

// 3:31 ~ 4:10

using namespace std;

bool isAlreadyAdded(vector<vector<int>> answer, vector<int> candidate) {
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].size() > candidate.size()) continue;
		bool isSame = true;
		for (int j = 0; j < answer[i].size(); j++) {
			bool isExist = false;
			for (int k = 0; k < candidate.size(); k++) {
				if (answer[i][j] == candidate[k]) isExist = true;
			}
			if (!isExist) {
				isSame = false;
				break;
			}
		}
		if (isSame) return true;
	}
	return false;
}

int solution(vector<vector<string>> relation) {
	int row = relation.size();
	int column = relation[0].size();

	vector<vector<int>> answer;

	// 1. i개로 후보키 조합 구하기
	for (int i = 1; i <= column; i++) {
		vector<int> comb(column, 0);
		for (int j = 0; j < i; j++) { comb[j] = 1; }

		do {
			set<string> S;
			vector<int> candidate;

			for (int j = 0; j < column; j++) {
				if (comb[j] == 1) candidate.push_back(j);
			}

			// 2. 후보키인지 판별 - 유일성
			bool isCandidateKey = true;
			for (int r = 0; r < row; r++) {
				string key = "";
				for (int c = 0; c < candidate.size(); c++)
					key += relation[r][candidate[c]];

				if (S.find(key) == S.end()) S.insert(key);
				else { isCandidateKey = false; break; }
			}
			// 3. 후보키인지 판별 - 최소성
			if (isCandidateKey && !isAlreadyAdded(answer, candidate)) {
				answer.push_back(candidate);
			}

		} while (prev_permutation(comb.begin(), comb.end()));
	}

	cout<< answer.size();
	return answer.size();
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	solution(
		{ {"100", "ryan", "music", "2"},
		{"200", "apeach", "math", "2"},
		{"300", "tube", "computer", "3"},
		{"400", "con", "computer", "4"},
		{"500", "muzi", "music", "3"},
		{"600", "apeach", "music", "2"} }
	);


	return 0;
}
