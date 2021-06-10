//
//  4963섬의개수.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool isValid(const int x, const int y, const int w, const int h) {
    return x >=0 && x < h && y >= 0 && y < w;
}

void bfs(const vector<vector<int>>& field, vector<vector<bool>>& flag, const pair<int, int>& start, const int w, const int h) {
    queue<pair<int, int>> que;
    
    que.push(start);
    flag[start.first][start.second] = true;
    
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny, w, h) == false) continue;
            if (flag[nx][ny] == true) continue;
            if (field[nx][ny] == 0) continue;
            
            que.push(make_pair(nx, ny));
            flag[nx][ny] = true;
        }
    }
    
}

int main(void) {
    int w, h, input;
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        vector<vector<int>> field(h, vector<int>(w, 0));
        vector<vector<bool>> flag(h, vector<bool>(w, false));
        for(int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> input;
                field[i][j] = input;
            }
        }
        
        int count = 0;
        for(int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (field[i][j] == 1 && flag[i][j] == false) {
                    count += 1;
                    bfs(field, flag, make_pair(i, j), w, h);
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
