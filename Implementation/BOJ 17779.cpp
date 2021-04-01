#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int A[21][21];
int temp[21][21];
int N, res=INT_MAX;

void boundary(int x, int y, int d1, int d2) {
	int sum, mmax = INT_MIN, mmin = INT_MAX;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			temp[i][j] =  A[i][j];

	//5번 선거구
	sum = 0;
	int r = x, y1 = 0, y2 = 0;
	bool isY1Decreasing = true, isY2Increasing = true;
	do {
		for (int c = y + y1; c <= y + y2; c++) {
			sum += temp[r][c];
			temp[r][c] = 0;
		}
		r++;

		if (isY1Decreasing) y1--;
		else y1++;

		if (isY2Increasing) y2++;
		else y2--;

		if (y1 == -d1) isY1Decreasing = false;
		if (y2 == d2) isY2Increasing = false;

	} while (r <= x + d1 + d2);
	mmax = max(mmax, sum);
	mmin = min(mmin, sum);

	//1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
	sum = 0;
	for (int r = 1; r < x + d1; r++)
		for (int c = 1; c <= y; c++)
			sum += temp[r][c];
	mmax = max(mmax, sum);
	mmin = min(mmin, sum);

	//2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
	sum = 0;
	for (int r = 1; r <= x + d2; r++) 
		for (int c = y+1; c <= N; c++) 
			sum += temp[r][c];
	mmax = max(mmax, sum);
	mmin = min(mmin, sum);

	//3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
	sum = 0;
	for (int r = x+d1; r <= N; r++) 
		for (int c = 1; c < y - d1 +d2; c++) 
			sum += temp[r][c];
	mmax = max(mmax, sum);
	mmin = min(mmin, sum);

	//4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
	sum = 0;
	for (int r = x+d2+1; r <=N; r++) 
		for (int c = y -d1+d2; c <= N; c++) 
			sum += temp[r][c];
	mmax = max(mmax, sum);
	mmin = min(mmin, sum);
	
	res = min(res, mmax - mmin);
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 > N || y - d1<1 || y + d2>N) continue;
					boundary(x, y, d1, d2);
				}
			}
		}
	}

	cout << res;

	return 0;
}