#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* ���� Ȱ��
* �� value�� �ִ� ���� �ƴ϶� index�� �־ �ذ��� �ȴ�.
* ���ÿ� �ִ� index�� ������Ʈ�ذ��� ���� ã�� ���
*/

int n;
int A[1'000'000];
vector<int> NGE(1'000'000, -1);

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	stack<int> S;

	for (int i = 0; i < n; i++) {
		while (!S.empty() && A[S.top()]< A[i]) {
			NGE[S.top()] = A[i];
			S.pop();
		}
		S.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << NGE[i] << ' ';
	}

	return 0;
}