//
//  2210숫자판점프.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/13.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

bool isValid(int x, int y) {
    return x >= 0 && x <= 4 && y >= 0 && y <= 4;
}

void bfs(const vector<vector<int>>& board, set<string>& answer, const pair<int, int>& start) {
    queue<pair<int,int>> que;
    que.push(start);
    
    queue<string> strQue;
    string newStr = to_string(board[start.first][start.second]);
    strQue.push(newStr);
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        newStr = strQue.front();
        strQue.pop();
        
        if (newStr.length() >= 6) {
            answer.insert(newStr);
            continue;;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny) == false) continue;
            
            que.push(make_pair(nx, ny));
            strQue.push(newStr + to_string(board[nx][ny]));
        }
    }
    
}

int main(void) {
    vector<vector<int>> board(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    set<string> answer;
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) bfs(board, answer, make_pair(i, j));
    cout << answer.size();
    return 0;
}
