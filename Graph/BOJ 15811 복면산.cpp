#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char str[3][20]; // �Է� string ����

int number[3];	// string�� ���ڷ� ��ȯ�Ͽ� ������ ����
int numOfAlphabet[26] = {-1};	// �� ���ĺ��� �ش��ϴ� ���ڸ� ������ ����

bool isExistAlphabet[26] = { false };	// �Է� string�� ���ĺ����� ���翩�θ� ������ ����
bool isUsedNumber[10] = { false };		// 0~9������ ���ڸ� ����ߴ��� üũ�� ����

bool isBokMyunSan = false;		

vector<int> alphabet;		// �����ϴ� ���ĺ��� ���� ����

int getNumber(string str) {
	int result = 0;
	int ind;
	for (int i =0; i < str.size(); i++) {
		ind = str[i] - 'A';
		result = result * 10 + numOfAlphabet[ind];
	}
	return result;
}

void dfs(int level) {
	if (isBokMyunSan) return;
	if (level == alphabet.size()) {
		for (int i = 0; i < 3; i++) {
			number[i] = getNumber(str[i]);
		}
		if (number[0] + number[1] == number[2]) {
			isBokMyunSan = true;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			// 1. 0~9 �� �Ҵ���� ���� ���ڸ� ���ĺ��� �Ҵ�
			if (!isUsedNumber[i]) {
				isUsedNumber[i] = true;
				numOfAlphabet[alphabet[level]] = i;
				// 2. ���� ���ĺ����� �̵�
				dfs(level + 1);
				// 3. ��Ͱ� ���� �� ���ƿ��� ����ߴ� ���� �ݳ�
				isUsedNumber[i] = false;
			}
		}
	}
}

int main() {
	// 1. �Է�
	for (int i = 0;i < 3; i++) {
		scanf("%s", str[i]);
	}

	// 2. �Էµ� ���ĺ��� ����
	int ind;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; str[k][i] != '\0'; i++) {
			ind = str[k][i] - 'A';
			if (!isExistAlphabet[ind]) isExistAlphabet[ind] = true;
		}
	}

	// 3. �ߺ��� ������ ���ĺ� ����Ʈ -> alphabetList
	for (int i = 0; i < 26; i++) {
		if (isExistAlphabet[i]) 
			alphabet.push_back(i);
	}

	dfs(0);

	if (isBokMyunSan) printf("YES\n");
	else printf("NO\n");

	return 0;
}