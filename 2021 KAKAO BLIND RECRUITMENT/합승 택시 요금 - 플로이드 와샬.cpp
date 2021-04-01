#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100'000'000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n+1, vector<int>(n+1, MAX));
    
    for(int i=0;i<fares.size();i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    
    for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

    int answer = MAX;
    for (int i = 1; i <= n; i++) {
            answer = min(answer, dist[s][i] + dist[i][a]+dist[i][b]);
    }
    
    return answer;
}