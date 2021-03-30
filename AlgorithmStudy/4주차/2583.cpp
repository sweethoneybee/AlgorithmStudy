//
//  2583.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void coloringField(vector<vector<int>>&, pair<int, int>, pair<int, int>);
int bfs(vector<vector<int>>&, pair<int, int>);
bool isValidCoord(int, int, int, int);

int main(void) {
    int M, N, K;
    cin >> M >> N >> K;
    
    vector<vector<int>> field(M, vector<int>(N, 0));
    for(int i = 0; i < K; i++) {
        int leftX, leftY, rightX, rightY;
        cin >> leftY >> leftX >> rightY >> rightX;
        
        coloringField(field, make_pair(leftX, leftY), make_pair(rightX, rightY));
    }
    
    vector<int> answers;
    for(int x = 0; x < M; x++) {
        for(int y = 0; y < N; y++) {
            if (field[x][y] == 1)
                continue;
            
            int blockCount = bfs(field, make_pair(x, y));
            answers.push_back(blockCount);
        }
    }
    
    sort(answers.begin(), answers.end());
    cout << answers.size() << endl;
    for(const auto& answer: answers) {
        cout << answer << " ";
    }
    
    return 0;
}

void coloringField(vector<vector<int>>& field, pair<int, int> leftCoord, pair<int, int> rightCoord) {
    for(int x = leftCoord.first; x < rightCoord.first; x++) {
        for(int y = leftCoord.second; y < rightCoord.second; y++) {
            field[x][y] = 1;
        }
    }
}

int bfs(vector<vector<int>>& field, pair<int, int> startCoord) {
    int blockCount = 0;
    queue<pair<int, int>> que;
    
    que.push(startCoord);
    field[startCoord.first][startCoord.second] = 1;
    blockCount += 1;
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while(que.empty() != true) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            int maxX = field.size() - 1;
            int maxY = field.front().size() - 1;
            if (isValidCoord(maxX, maxY, nx, ny)
                && field[nx][ny] == 0) {
                que.push(make_pair(nx, ny));
                field[nx][ny] = 1;
                blockCount += 1;
            }
        }
    }
    return blockCount;
}

bool isValidCoord(int maxX, int maxY, int x, int y) {
    if (x >= 0 && x <= maxX && y >= 0 && y <= maxY) {
        return true;
    }
    return false;
}
