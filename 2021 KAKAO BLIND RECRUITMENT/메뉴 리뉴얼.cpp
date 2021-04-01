#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// [��ü process]
// 1. ���� ���ϱ�
// 2. ���� ���� �ֹ��� �͵� ���ϱ�
// 3. answer�� �߰� �� ����

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
		//���� �ִ°��
		if (j == limit) cnt++;
	}
	return cnt;
}

void dfs(vector<string> orders, int level, int pos, int limit) {
	if (level == limit) {
		// �� ���տ� ���� ��� ���Դ��� ����
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

	// 1. ������ ���ĺ� ���ϱ�
	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			int ind = orders[i][j] - 'A';
			isAlphabetExist[ind] = true;
		}
	}

	// 2. �����ϴ� ���ĺ��� �����ϱ�
	for (int i = 0; i < 26; i++) {
		if (isAlphabetExist[i]) {
			alphabetArray.push_back(i + 'A');
			isAlphabetChecked.push_back(false);
		}
	}

	// 3. �� n���� �ڽ��� ���� solution
	for (int i = 0; i < course.size(); i++) {
		for (int j = 0; j < isAlphabetChecked.size(); j++) {
			isAlphabetChecked[j] = false;
		}

		// 4. ���� ���ϱ�
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
