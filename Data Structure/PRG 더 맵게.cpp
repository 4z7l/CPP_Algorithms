#include <string>
#include <vector>
#include <queue>

using namespace std;

struct scov {
	int level;
	bool operator<(const scov& s) const {
		return level > s.level;
	}
};

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<scov> pQ;

	for (int i = 0; i < scoville.size(); i++) {
		pQ.push({ scoville[i] });
	}

	int a, b;
	while (pQ.top().level < K && pQ.size()>1) {
		a = pQ.top().level;
		pQ.pop();
		b = pQ.top().level;
		pQ.pop();

		answer++;
		pQ.push({ a + b * 2 });
	}

	if (pQ.top().level < K) return -1;

	return answer;
}