#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 5:14 ~ 5:25

pair<int, int> getPosition(int number) {
	pair<int, int> arr[] = 
	{ {3,1}, {0,0},{0,1},{0,2}
			,{1,0},{1,1},{1,2}
			,{2,0},{2,1},{2,2} };
	return arr[number];
}

char getHand(int number, pair<int, int> lhand, pair<int, int> rhand, string hand) {
	pair<int, int> pos = getPosition(number);
	int ldiff = abs(pos.first - lhand.first) + abs(pos.second - lhand.second);
	int rdiff = abs(pos.first - rhand.first) + abs(pos.second - rhand.second);

	if (ldiff < rdiff) return 'L';
	else if (ldiff > rdiff) return 'R';
	else {
		if (hand == "right") return 'R';
		else return 'L';
	}
}

string solution(vector<int> numbers, string hand) {
	// 1 4 7 L
	// 3 6 9 R
	// 2 5 8 0 ?
	pair<int, int> lhand = { 3,0 };
	pair<int, int> rhand = { 3,2 };

	string answer = "";
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer.push_back('L');
			lhand = getPosition(numbers[i]);
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer.push_back('R');
			rhand = getPosition(numbers[i]);
		}
		else {
			char ch = getHand(numbers[i], lhand, rhand, hand);
			if (ch == 'L') {
				answer.push_back('L');
				lhand = getPosition(numbers[i]);
			}
			else {
				answer.push_back('R');
				rhand = getPosition(numbers[i]);
			}
		}
	}


	return answer;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cout<<solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");

	return 0;
}
