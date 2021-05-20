//
//  2636치즈.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int W, H;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(const int x, const int y) {
    return x >= 0 && x < H && y >=0 && y < W;
}

void bfs(const vector<vector<bool>>& cheese, vector<vector<bool>>& flag, set<pair<int, int>>& willMelt, const pair<int, int>& start) {
    queue<pair<int, int>> que;
    que.push(start);
    flag[start.first][start.second] = true;
    
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false || flag[nx][ny]) continue;
            if (cheese[nx][ny] == true) {
                willMelt.insert(make_pair(nx, ny));
                flag[nx][ny] = true;
            } else {
                que.push(make_pair(nx, ny));
                flag[nx][ny] = true;
            }
        }
    }
}

int melting(vector<vector<bool>>& cheese) {
    vector<vector<bool>> flag(H, vector<bool>(W, false));
    set<pair<int ,int>> willMelt;
    bfs(cheese, flag, willMelt, make_pair(0, 0));
    for(const auto& m: willMelt) cheese[m.first][m.second] = false;
    return willMelt.size();
}

pair<int, int> solution(vector<vector<bool>>& cheese) {
    int cheeseCount = 0, meltCount = 0, hour = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (cheese[i][j] == true) cheeseCount += 1;
        }
    }
        
    while (cheeseCount > 0) {
        hour += 1;
        meltCount = melting(cheese);
        cheeseCount -= meltCount;
    }
    
    return make_pair(hour, meltCount);
}

int main(void) {
    cin >> H >> W;
    
    bool input;
    vector<vector<bool>> cheese(H, vector<bool>(W, false));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> input;
            cheese[i][j] = input;
        }
    }
            
    pair<int, int> answer = solution(cheese);
    cout << answer.first << endl << answer.second;
    
    return 0;
}

