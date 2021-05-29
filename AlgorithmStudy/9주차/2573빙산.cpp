//
//  2573빙산.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(const int x, const int y) {
    return x >= 0 && x <= N - 1 && y >= 0 && y <= M - 1;
}

void bfs(const vector<vector<int>>& ice, vector<vector<bool>>& flag, const pair<int, int>& start) {
    queue<pair<int, int>> que;
    
    que.push(start);
    flag[start.first][start.second] = true;
    
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false) continue;
            if (flag[nx][ny] == true) continue;
            if (ice[nx][ny] <= 0) continue;
            
            que.push(make_pair(nx, ny));
            flag[nx][ny] = true;
        }
    }
}

void meltIce(vector<vector<int>>& ice, vector<vector<bool>>& flag, const pair<int, int>& start, map<pair<int, int>, int>& m) {
    queue<pair<int, int>> que;
    
    que.push(start);
    flag[start.first][start.second] = true;
    
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false) continue;
            if (ice[nx][ny] > 0) {
                m[make_pair(nx, ny)] += 1;
                continue;
            }
            
            if (flag[nx][ny] == true) continue;
            
            que.push(make_pair(nx, ny));
            flag[nx][ny] = true;
        }
    }
}

int solution(const vector<vector<int>>& originalIce) {
    int ret = 0;
    
    vector<vector<int>> ice(originalIce);
    map<pair<int, int>, int> m;
    for(int year = 1;;year++) {
        vector<vector<bool>> flag(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if (ice[i][j] == 0 && flag[i][j] == false) {
                    meltIce(ice, flag, make_pair(i, j), m);
                }
            }
        }
        
        for(const auto& willMelt: m) {
            const auto& coord = willMelt.first;
            const auto& howMuch = willMelt.second;
            
            ice[coord.first][coord.second] -= howMuch;
            if (ice[coord.first][coord.second] < 0) ice[coord.first][coord.second] = 0;
        }
        m.clear();
        
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if (ice[i][j] > 0 && flag[i][j] == false) {
                    count += 1;
                    bfs(ice, flag, make_pair(i, j));
                }
            }
        }
        
        if (count >= 2) {
            ret = year;
            break;
        } else if (count == 0) {
            ret = 0;
            break;
        }
    }
    
    return ret;
}

int main(void) {
    cin >> N >> M;
    vector<vector<int>> ice(N, vector<int>(M, 0));
    int input;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            ice[i][j] = input;
        }
    }
    
    cout << solution(ice);
    return 0;
}
