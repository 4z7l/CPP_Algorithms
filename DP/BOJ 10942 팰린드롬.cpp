#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
* 21.04.07 3:53PM ~ 4.35PM
* 
* [해결 과정]
* (1) 처음 생각한 방법 : 하나하나 검사하기
* 예상 연산 횟수 : 2,000 * 1,000,000 = 20억번
* 
* (2) DP
* 일단 종이에 그려보고 규칙을 찾음 -> 코드로 옮기기
* 
* [예외 발생]
* 2
* 1 1
* 1
* 1 2
* 일때 오답 출력
* 
* palindrom[i][i+1]일 때를 초기화해주어야함
* 
*/

int arr[2001];
bool palindrom[2001][2001] = { false, };

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1])
			palindrom[i][i + 1] = true;
	}

	for (int i = 1; i <= n; i++) {
		palindrom[i][i] = true;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true) {
				palindrom[i][j] = true;
			}
		}
	}

	int m, s, e;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << palindrom[s][e] << '\n';
	}

	return 0;
}