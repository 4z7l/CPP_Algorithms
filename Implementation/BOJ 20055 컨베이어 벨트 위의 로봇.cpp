#include <iostream>
#include <string>
#include <vector>

using namespace std;

int zeroCnt = 0;
int N, K;
int A[201];
bool robot[201] = {false,};

void input();
void rotate_belt();
void move_robot();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	input();
	
	int stage = 0;
	while (zeroCnt<K) {
		rotate_belt();
		move_robot();
		stage++;
	}
	cout << stage;

	return 0;
}

void input() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> A[i];
		if (A[i] == 0) zeroCnt++;
	}
}

void rotate_belt() {
	int temp = A[2*N];
	for (int i = 2 * N; i > 1; i--) {
		A[i] = A[i - 1];
	}
	A[1] = temp;

	for (int i = N; i > 1; i--) {
		robot[i] = robot[i - 1];
	}
	robot[1] = false;
	robot[N] = false;
}

void move_robot() {
	for (int i = N-1; i >= 1; i--) {
		if (robot[i] && !robot[i+1] && A[i+1]>0) {
			robot[i] = false;
			robot[i + 1] = true;
			A[i + 1]--;
			if (A[i + 1] == 0) zeroCnt++;
		}
	}
	//내려가는 위치
	if (robot[N]) {
		robot[N] = false;
	}
	//올라가는 위치
	if (!robot[1] && A[1] > 0) {
		robot[1] = true;
		A[1]--;
		if (A[1] == 0) zeroCnt++;
	}
}