#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 2:40PM ~ 3:04PM

bool board[500][500] = {false,};

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int h, w, b;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> b;
		for (int j = h-b; j < h; j++) {
			board[j][i] = true;
		}
	}

	int res = 0;
	int s=-1, e=-1;
	for (int i = 0; i < h; i++) {
		s = -1; e = -1;
		for (int j = 0; j < w; j++) {
			if (board[i][j]) {
				if (s == -1) s = j;
				else e = j;
			}
			if (s != -1 && e != -1) {
				res += e - s - 1;
				s = j; e = -1;
			}
		}
	}

	cout << res;

	return 0;
}
