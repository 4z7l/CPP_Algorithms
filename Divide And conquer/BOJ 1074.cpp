#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, r, c;
int number = 0;

void divide(int sx, int sy, int size) {
	if (sx == r && sy == c) {
		cout << number;
		return;
	}
	if (sx <= r && r < sx + size && sy <= c && c < sy + size) {
		divide(sx, sy, size / 2);
		divide(sx, sy + size / 2, size / 2);
		divide(sx + size / 2, sy, size / 2);
		divide(sx + size / 2, sy + size / 2, size / 2);
	}
	else {
		number += size * size;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> r >> c;

	divide(0,0, pow(2,n));

	return 0;
}