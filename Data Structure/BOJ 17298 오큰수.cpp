#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* 스택 활용
* 꼭 value를 넣는 것이 아니라 index를 넣어도 해결이 된다.
* 스택에 있는 index를 업데이트해가며 답을 찾는 방식
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