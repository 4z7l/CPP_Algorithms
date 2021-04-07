#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
* 21.04.07 3:53PM ~ 4.35PM
* 
* [�ذ� ����]
* (1) ó�� ������ ��� : �ϳ��ϳ� �˻��ϱ�
* ���� ���� Ƚ�� : 2,000 * 1,000,000 = 20���
* 
* (2) DP
* �ϴ� ���̿� �׷����� ��Ģ�� ã�� -> �ڵ�� �ű��
* 
* [���� �߻�]
* 2
* 1 1
* 1
* 1 2
* �϶� ���� ���
* 
* palindrom[i][i+1]�� ���� �ʱ�ȭ���־����
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