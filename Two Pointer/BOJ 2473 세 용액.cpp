#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2:17PM ~ 2:34PM

long long arr[5000];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int p1, p2, p3, a = 0, b = 1, c = 2;
	for (int i = 0; i < n - 2; i++) {
		p1 = i;
		p2 = i + 1;
		p3 = n - 1;
		while (p2 < p3) {
			if (abs(arr[p1] + arr[p2] + arr[p3]) < abs(arr[a] + arr[b] + arr[c])) {
				a = p1;
				b = p2;
				c = p3;
			}

			if (arr[p1] + arr[p2] + arr[p3] < 0) p2++;
			else p3--;
		}
	}

	cout << arr[a] << ' ' << arr[b] << ' ' << arr[c];

	return 0;
}
