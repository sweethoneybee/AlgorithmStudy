//
//  1012.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int simulating();
void bfs(const vector<vector<int>>& field, vector<vector<bool>>& flag, int startX, int startY);
bool isValidCoord(int maxX, int maxY, int x, int y);

int simulating() {
    int needWormCount = 0;
    int M, N, K;
    cin >> M >> N >> K;
    
    vector<int> forInitField(M, 0);
    vector<vector<int>> field(N, forInitField);

    vector<bool> forInitFlag(M, 0);
    vector<vector<bool>> flag(N, forInitFlag);
    
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> y >> x;
        field[x][y] = 1;
    }
    
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            if (field[x][y] == 1 && flag[x][y] == false) {
                needWormCount += 1;
                bfs(field, flag, x, y);
            }
        }
    }
    return needWormCount;
}

void bfs(const vector<vector<int>>& field, vector<vector<bool>>& flag, int startX, int startY) {
    queue<pair<int, int>> que;
    que.push(make_pair(startX, startY));
    flag[startX][startY] = true;
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while(que.empty() != true) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValidCoord(field.size() - 1, field.front().size() - 1, nx, ny) == false)
                continue;
            
            if (field[nx][ny] == 1 && flag[nx][ny] == false) {
                que.push(make_pair(nx, ny));
                flag[nx][ny] = true;
            }
        }
    }
}

bool isValidCoord(int maxX, int maxY, int x, int y) {
    if (x >= 0 && x <= maxX && y >= 0 && y <= maxY)
        return true;
    else
        return false;
}

int main(void) {
    int testcase = 0;
    cin >> testcase;
    
    vector<int> answers;
    for(int i = 0; i < testcase; i++) {
        answers.push_back(simulating());
    }
    
    for(const auto& answer: answers) {
        cout << answer << endl;
    }
    
    return 0;
}
