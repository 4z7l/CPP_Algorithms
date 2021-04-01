#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// [전체 process]
// 1. 조합 구하기
// 2. 가장 많이 주문된 것들 구하기
// 3. answer에 추가 후 정렬

bool isAlphabetExist[26] = {false,};
vector<char> alphabetArray;
vector<bool> isAlphabetChecked;
char selectedCourse[11];
vector<string> tempAnswer;
int tempMax = 0;

int counting_menu(vector<string> orders, int limit) {
	int cnt = 0;
	for (int i = 0; i < orders.size(); i++) {
		int j;
		for (j = 0; j < limit; j++) {
			if (orders[i].find(selectedCourse[j]) == string::npos) break;
		}
		//조합 있는경우
		if (j == limit) cnt++;
	}
	return cnt;
}

void dfs(vector<string> orders, int level, int pos, int limit) {
	if (level == limit) {
		// 각 조합에 대해 몇번 나왔는지 세기
		int res = counting_menu(orders, limit);
		if (tempMax <= res) {
			if (tempMax < res) {
				tempMax = res;
				tempAnswer.clear();
			}
			string combination = "";
			for (int i = 0; i < level; i++)
				combination += selectedCourse[i];
			tempAnswer.push_back(combination);
		}
	}
	else {
		for (int i = pos; i < isAlphabetChecked.size(); i++) {
			if (!isAlphabetChecked[i]) {
				isAlphabetChecked[i] = true;
				selectedCourse[level] = alphabetArray[i];
				dfs(orders, level+1, i+1, limit);
				isAlphabetChecked[i] = false;
			}
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

	// 1. 출현한 알파벳 구하기
	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			int ind = orders[i][j] - 'A';
			isAlphabetExist[ind] = true;
		}
	}

	// 2. 존재하는 알파벳만 추출하기
	for (int i = 0; i < 26; i++) {
		if (isAlphabetExist[i]) {
			alphabetArray.push_back(i + 'A');
			isAlphabetChecked.push_back(false);
		}
	}

	// 3. 각 n개의 코스에 대해 solution
	for (int i = 0; i < course.size(); i++) {
		for (int j = 0; j < isAlphabetChecked.size(); j++) {
			isAlphabetChecked[j] = false;
		}

		// 4. 조합 구하기
		tempAnswer.clear();
		tempMax = 2;
		dfs(orders, 0, 0, course[i]);

		for (int j = 0; j < tempAnswer.size(); j++) {
			answer.push_back(tempAnswer[j]);
		}
	}

	sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" },
		{2,3,4});

	return 0;
}
