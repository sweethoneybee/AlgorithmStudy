//
//  2206벽부수고이동하기.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAX = 1873924930;
int N, M;

bool isValid(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= M);
}

int bfs(const vector<vector<int>>& miro) {
    vector<vector<vector<int>>> dist(2, vector<vector<int>>(N + 1, vector<int>(M + 1, MAX)));
    queue<pair<int, int>> que;
    queue<pair<int, int>> wallQue;
    
    que.push(make_pair(1, 1)); // coord X, Y
    wallQue.push(make_pair(0, 1)); // wall destroy count, cost
    dist[0][1][1] = 1;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        int wall = wallQue.front().first;
        int cost = wallQue.front().second;
        wallQue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false) continue;
            if (miro[nx][ny] == 1 && wall == 0 && dist[wall + 1][nx][ny] > cost + 1) {
                que.push(make_pair(nx, ny));
                wallQue.push(make_pair(wall + 1, cost + 1));
                dist[wall + 1][nx][ny] = cost + 1;
                continue;
            }
            if (miro[nx][ny] == 0 && dist[wall][nx][ny] > cost + 1) {
                que.push(make_pair(nx, ny));
                wallQue.push(make_pair(wall, cost + 1));
                dist[wall][nx][ny] = cost + 1;
            }
        }
    }
    
    int ret = dist[0][N][M] < dist[1][N][M] ? dist[0][N][M] : dist[1][N][M];
    return (ret == MAX) ? -1 : ret;
}

int main(void) {
    cin >> N >> M;
    string line;
    vector<vector<int>> miro(N + 1, vector<int>(M + 1));
    for(int i = 1; i <= N; i++) {
        cin >> line;
        for(int j = 0; j < M; j++) miro[i][j + 1] = line[j] - '0';
    }
    
    cout << bfs(miro);
    return 0;
}
