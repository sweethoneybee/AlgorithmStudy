//
//  10026.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/31.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void bfs(const vector<string>& picture, vector<vector<bool>>& flag, pair<int, int> startCoord, char startColor);
void bfsForDisabled(const vector<string>& picture, vector<vector<bool>>& flag, pair<int, int> startCoord, char startColor);
bool isValidCoord(int maxX, int maxY, int x, int y);

int main(void) {
    int N;
    cin >> N;
    vector<string> picture;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        picture.push_back(input);
    }

    vector<vector<bool>> flag(N, vector<bool>(N, false));
    vector<vector<bool>> flagForDisabled(N, vector<bool>(N, false));
    int countForDisabled = 0;
    int count = 0;
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            if (flag[x][y] == false) {
                count += 1;
                bfs(picture, flag, make_pair(x, y), picture[x][y]);
            }
            
            if (flagForDisabled[x][y] == false) {
                countForDisabled += 1;
                bfsForDisabled(picture, flagForDisabled, make_pair(x, y), picture[x][y]);
            }
        }
    }
    
    cout << count << " " << countForDisabled;
    return 0;
}

void bfs(const vector<string>& picture, vector<vector<bool>>& flag, pair<int, int> startCoord, char startColor) {
    queue<pair<int ,int>> que;
    queue<char> colorQue;

    flag[startCoord.first][startCoord.second] = true;
    que.push(make_pair(startCoord.first, startCoord.second));
    colorQue.push(startColor);

    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};
    while(que.empty() != true) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        char color = colorQue.front();
        colorQue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int maxX = picture.size() - 1;
            int maxY = picture.front().size() - 1;
            if (isValidCoord(maxX, maxY, nx, ny) == false)
                continue;
            
            if (picture[nx][ny] == color
                && flag[nx][ny] == false) {
                flag[nx][ny] = true;
                que.push(make_pair(nx, ny));
                colorQue.push(picture[nx][ny]);
            }
        }
    }
}

void bfsForDisabled(const vector<string>& picture, vector<vector<bool>>& flag, pair<int, int> startCoord, char startColor) {
    queue<pair<int ,int>> que;
    queue<char> colorQue;
    
    flag[startCoord.first][startCoord.second] = true;
    que.push(make_pair(startCoord.first, startCoord.second));
    colorQue.push(startColor);
    
    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};
    while(que.empty() != true) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        char color = colorQue.front();
        colorQue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int maxX = picture.size() - 1;
            int maxY = picture.front().size() - 1;
            if (isValidCoord(maxX, maxY, nx, ny) == false)
                continue;
            
            if (color == 'R' || color == 'G') {
                if ((picture[nx][ny] == 'R' || picture[nx][ny] == 'G')
                    && flag[nx][ny] == false) {
                    flag[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                    colorQue.push(picture[nx][ny]);
                }
            } else {
                if (picture[nx][ny] == color
                    && flag[nx][ny] == false) {
                    flag[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                    colorQue.push(picture[nx][ny]);
                }
            }
        }
    }
}

bool isValidCoord(int maxX, int maxY, int x, int y) {
    if (x >= 0 && x <= maxX && y >= 0 && y <= maxY) {
        return true;
    }
    return false;
}
