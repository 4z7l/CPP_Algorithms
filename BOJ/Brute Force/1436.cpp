#include <iostream>
#include <string>

using namespace std;

int main() {
	int start = 666, cnt = 0, temp;
	int n;
	cin >> n;

	while (true) {
		temp = start;

		/* 숫자 안에 666이 있는지 확인 */
		do {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}while(temp>0);

		/* n번째 숫자를 찾으면 출력 */
		if (cnt == n) {
			cout << start << endl;
			break;
		}

		start++;
	}

	return 0;
}