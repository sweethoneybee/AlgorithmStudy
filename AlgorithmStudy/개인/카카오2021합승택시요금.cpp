//
//  카카오2021합승택시요금.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/07.
//

#include <string>
#include <vector>

using namespace std;
const int MAX = 999999999;

void floydWarshall(vector<vector<int>>& dist, const int n) {
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // init
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAX));
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(const auto& fare: fares) {
        int c = fare[0], d = fare[1], f = fare[2];
        dist[c][d] = f;
        dist[d][c] = f;
    }
    
    // Floyd-Warshall
    floydWarshall(dist, n);
    
    int answer = MAX;
    for(int k = 1; k <= n; k++) {
        if (dist[s][k] != MAX) { // reachable
        int d = dist[s][k] + dist[k][a] + dist[k][b];
        if (answer > d) answer = d;
        }
    }
    
    return answer;
}

int main(void) {
    return 0;
}
