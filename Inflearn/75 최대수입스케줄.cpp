#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class seminar {
public:
	int pay;
	int day;
	seminar(int p, int d) {
		pay = p; day = d;
	}
	const bool operator <(const seminar& s) {
		if (day == s.day) return pay > s.pay;
		return day > s.day;
	}
};


int main() {
	int n;
	scanf("%d", &n);

	int m, d;
	vector<seminar> v;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &m, &d);
		v.push_back(seminar(m, d));
	}
	sort(v.begin(), v.end());

	priority_queue<int> pQ;
	int sum = 0;
	int day = v[0].day;

	int j=0;
	for (int i = day; i > 0; i--) {
		for ( ; j < n; j++) {
			if (v[j].day != i) break;
			pQ.push(v[j].pay);
		}
		if (!pQ.empty()) {
			sum += pQ.top();
			pQ.pop();
		}
	}

	printf("%d", sum);

	return 0;
}