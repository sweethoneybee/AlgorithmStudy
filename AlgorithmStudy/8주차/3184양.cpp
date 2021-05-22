//
//  3184양.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/22.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(const int x, const int y) {
    return x >= 0 && x <= R - 1 && y >= 0 && y <= C - 1;
}

void bfs(const vector<string>& yard, vector<vector<bool>>& flag, int& sheep, int& wolf, const pair<int, int>& start) {
    int sheepCount = 0, wolfCount = 0;
    queue<pair<int, int>> que;
    que.push(start);
    flag[start.first][start.second] = true;
    if (yard[start.first][start.second] == 'o') sheepCount += 1;
    else if (yard[start.first][start.second] == 'v') wolfCount += 1;
    
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false || flag[nx][ny] == true) continue;
            if (yard[nx][ny] == '#') continue;
            
            flag[nx][ny] = true;
            que.push(make_pair(nx, ny));
            if (yard[nx][ny] == 'o') {
                sheepCount += 1;
            } else if (yard[nx][ny] == 'v') {
                wolfCount += 1;
            }
        }
    }
    
    if (sheepCount > wolfCount) wolf -= wolfCount;
    else sheep -= sheepCount;
}

int main(void) {
    cin >> R >> C;
    vector<string> yard;
    string input;
    for(int i = 0; i < R; i++) {
        cin >> input;
        yard.push_back(input);
    }
    
    int sheep = 0, wolf = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if (yard[i][j] == 'o') sheep += 1;
            else if (yard[i][j] == 'v') wolf += 1;
        }
    }
    
    vector<vector<bool>> flag(R, vector<bool>(C, false));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if (yard[i][j] != '#' && flag[i][j] == false) {
                bfs(yard, flag, sheep, wolf, make_pair(i, j));
            }
        }
    }
    
    cout << sheep << " " << wolf;
    
    return 0;
}
