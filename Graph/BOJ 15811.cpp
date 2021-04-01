#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char str[3][20]; // 입력 string 저장

int number[3];	// string을 숫자로 변환하여 저장할 공간
int numOfAlphabet[26] = {-1};	// 각 알파벳에 해당하는 숫자를 저장할 공간

bool isExistAlphabet[26] = { false };	// 입력 string의 알파벳들의 존재여부를 저장할 공간
bool isUsedNumber[10] = { false };		// 0~9까지의 숫자를 사용했는지 체크할 공간

bool isBokMyunSan = false;		

vector<int> alphabet;		// 존재하는 알파벳만 담은 공간

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
			// 1. 0~9 중 할당되지 않은 숫자를 알파벳에 할당
			if (!isUsedNumber[i]) {
				isUsedNumber[i] = true;
				numOfAlphabet[alphabet[level]] = i;
				// 2. 다음 알파벳으로 이동
				dfs(level + 1);
				// 3. 재귀가 끝난 후 돌아오면 사용했던 숫자 반납
				isUsedNumber[i] = false;
			}
		}
	}
}

int main() {
	// 1. 입력
	for (int i = 0;i < 3; i++) {
		scanf("%s", str[i]);
	}

	// 2. 입력된 알파벳만 구별
	int ind;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; str[k][i] != '\0'; i++) {
			ind = str[k][i] - 'A';
			if (!isExistAlphabet[ind]) isExistAlphabet[ind] = true;
		}
	}

	// 3. 중복을 제거한 알파벳 리스트 -> alphabetList
	for (int i = 0; i < 26; i++) {
		if (isExistAlphabet[i]) 
			alphabet.push_back(i);
	}

	dfs(0);

	if (isBokMyunSan) printf("YES\n");
	else printf("NO\n");

	return 0;
}