#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size(); i++) {
		//1�ܰ�
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
			new_id[i] = new_id[i] - 'A' + 'a';
		//2�ܰ�
		if (('a' <= new_id[i] && new_id[i] <= 'z')
			|| ('0' <= new_id[i] && new_id[i] <= '9')
			|| new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			//3�ܰ�
			if (answer.size() > 0 && answer[answer.size() - 1] == '.' && new_id[i] == '.')
				continue;
			else answer.push_back(new_id[i]);
		}
	}

	//4�ܰ�
	if (answer.size() > 0 && answer[0] == '.') answer.erase(0, 1);
	if (answer.size() > 0 && answer[answer.size() - 1] == '.') answer.pop_back();

	//5�ܰ�
	if (answer.size() == 0) answer = "a";

	//6�ܰ�
	if (answer.size() > 15) answer = answer.substr(0, 15);
	if (answer.size() > 0 && answer[answer.size() - 1] == '.') answer.pop_back();

	//7�ܰ�
	while (answer.size() <= 2) {
		answer.push_back(answer[answer.size() - 1]);
	}

	return answer;
}
