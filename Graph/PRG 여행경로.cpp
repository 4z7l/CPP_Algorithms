#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool isSolved = false;

void dfs(string start, vector<vector<string>>& tickets, vector<bool>& visit
, vector<string>& answer, vector<string>& temp, int cnt) {
	if (cnt == tickets.size()) {
		if (!isSolved) {
			isSolved = true;
			answer = temp;
		}
	}
	else {
		for (int i = 0; i < tickets.size(); i++) {
			if (tickets[i][0] == start && !visit[i]) {
				temp.push_back(tickets[i][1]);
				visit[i] = true;
				dfs(tickets[i][1], tickets, visit, answer, temp, cnt+1);
				visit[i] = false;
				temp.pop_back();
			}
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
	vector<bool> visit(tickets.size(), false);

	sort(tickets.begin(), tickets.end());

	temp.push_back("ICN");
	dfs("ICN", tickets, visit, answer, temp, 0);

    return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} });
	isSolved = false;
	solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });

	return 0;
}