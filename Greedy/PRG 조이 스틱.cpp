#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int turn = n - 1;
    for (int i = 0; i < n; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;
        
        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;
    return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cout << solution("ABABAAAAABA")<<'\n';
    cout << solution("JEROEN") << '\n';
    cout << solution("JAN") << '\n';

	return 0;
}