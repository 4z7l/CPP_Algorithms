#include <iostream>
#include <string>

using namespace std;

int main() {
	int start = 666, cnt = 0, temp;
	int n;
	cin >> n;

	while (true) {
		temp = start;

		/* ���� �ȿ� 666�� �ִ��� Ȯ�� */
		do {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}while(temp>0);

		/* n��° ���ڸ� ã���� ��� */
		if (cnt == n) {
			cout << start << endl;
			break;
		}

		start++;
	}

	return 0;
}