#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//40분 ~ 58분

vector<string> solution(vector<string> record) {
	vector<string> answer;

	// 1. uid 저장
	map<string, string> M;
	for (string rec : record) {
		if (rec[0] == 'L') continue;
		string uid = "", name = "";
		int i = 6;
		if (rec[0] == 'C') i = 7;
		while (i < rec.size() && rec[i] != ' ')uid.push_back(rec[i++]);
		i++;
		while (i < rec.size() && rec[i] != ' ')name.push_back(rec[i++]);
		M[uid] = name;
	}

	// 2. 출력
	for (string rec : record) {
		if (rec[0] == 'C') continue;
		string uid = "";
		for (int i = 6; i < rec.size() && rec[i] != ' '; i++) uid.push_back(rec[i]);
		string name = M[uid];
		if (rec[0] == 'E') answer.push_back(name + "님이 들어왔습니다.");
		else answer.push_back(name + "님이 나갔습니다.");
	}

	return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	vector<string> res = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

	for (string r : res) {
		cout << r << '\n';
	}

	return 0;
}