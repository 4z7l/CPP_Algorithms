#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isDifferentOneAlphabet(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt == 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    queue<pair<int, string>> pQ;
    pQ.push({ 0,begin });

    string w;
    int cnt;
    while (!pQ.empty()) {
        cnt = pQ.front().first;
        w = pQ.front().second;
        pQ.pop();

        if (w == target) return cnt;

        for (int i = 0; i < words.size(); i++) {
            if (isDifferentOneAlphabet(w, words[i])) {
                pQ.push({ cnt + 1, words[i] });
            }
        }
    }

    return 0;
}
