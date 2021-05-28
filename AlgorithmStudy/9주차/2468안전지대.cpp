//
//  2468안전지대.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(const int x, const int y) {
    return x >= 0 && x <= N - 1 && y >= 0 && y <= N - 1;
}

void bfs(vector<vector<bool>>& flag, const pair<int, int>& start) {
    queue<pair<int, int>> que;
    que.push(start);
    flag[start.first][start.second] = false;
    
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false || flag[nx][ny] == false) continue;
            
            que.push(make_pair(nx, ny));
            flag[nx][ny] = false;
        }
    }
}

int getRained(const vector<vector<int>>& field, const int rain) {
    vector<vector<bool>> flag(N, vector<bool>(N, true));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (field[i][j] <= rain) {
                flag[i][j] = false;
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (flag[i][j] == true) {
                bfs(flag, make_pair(i, j));
                count += 1;
            }
        }
    }
    return count;
}

int main(void) {
    cin >> N;
    vector<vector<int>> field(N, vector<int>(N, 0));
    int input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input;
            field[i][j] = input;
        }
    }
    
    int answer = 0;
    for(int rain = 0; rain <= 100; rain++) {
        int rained = getRained(field, rain);
        answer = max(answer, rained);
        if (rained == 0)
            break;
    }
    cout << answer;
    return 0;
}
