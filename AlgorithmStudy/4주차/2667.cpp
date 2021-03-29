//
//  2667.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(const vector<vector<int>>& field, vector<vector<bool>>& flag, int startX, int startY);
bool isVaildCoord(int maxX, int maxY, int x, int y);

int bfs(const vector<vector<int>>& field, vector<vector<bool>>& flag, int startX, int startY) {
    int count = 0;
    
    queue<pair<int, int>> que;
    que.push(make_pair(startX, startY));
    flag[startX][startY] = true;
    count += 1;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while(que.empty() != true) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isVaildCoord(field.size() - 1, field.front().size() - 1, nx, ny)
                && field[nx][ny] == 1
                && flag[nx][ny] == false) {
                que.push(make_pair(nx, ny));
                flag[nx][ny] = true;
                count += 1;
            }
        }
    }
    
    return count;
}

bool isVaildCoord(int maxX, int maxY, int x, int y) {
    if (x >= 0 && x <= maxX && y >= 0 && y <= maxY) {
        return true;
    }
    return false;
}

int main(void) {
    int N;
    cin >> N;
    
    vector<int> oneLineForField(N, 0);
    vector<vector<int>> field(N, oneLineForField);
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0, len = input.length(); j < len; j++) {
            field[i][j] = input[j] - '0';
        }
    }
    
    vector<bool> oneLineForFlag(N, false);
    vector<vector<bool>> flag(N, oneLineForFlag);
    vector<int> answers;
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            if (field[x][y] == 1 && flag[x][y] == false) {
                int apartCount = bfs(field, flag, x, y);
                answers.push_back(apartCount);
            }
        }
    }
    
    sort(answers.begin(), answers.end());
    cout << answers.size() << endl;
    for(const auto& answer: answers) {
        cout << answer << endl;
    }
    return 0;
}
