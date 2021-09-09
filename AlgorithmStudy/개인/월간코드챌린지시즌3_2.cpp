//
//  월간코드챌린지시즌3_2.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/09.
//

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using Field = vector<vector<vector<bool>>>;

struct ThreePair {
    int first, second, third;
    ThreePair(int a, int b, int c) : first(a), second(b), third(c){};
};

unsigned long rowLen = 0;
unsigned long columnLen = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(const vector<string>&, Field&, const ThreePair&, vector<int>&);
void optimizeCoord(int&, int&);

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    rowLen = grid.size();
    columnLen = grid.front().size();
    Field field(rowLen, vector<vector<bool>>(columnLen, vector<bool>(4, false)));
    
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < columnLen; j++) {
            for (int k = 0; k < 4; k++) {
                if (field[i][j][k] == false) {
                    ThreePair start(i, j, k);
                    bfs(grid, field, start, answer);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

void bfs(const vector<string>& grid, Field& field, const ThreePair& start, vector<int>& answer) {
    field[start.first][start.second][start.third] = true;
    queue<ThreePair> que;
    que.push(start);
    int cycleLength = 1;
    
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        int dirIndex = que.front().third;
        que.pop();
        
        switch (grid[x][y]) {
            case 'L':
                dirIndex = (dirIndex + 1) % 4;
                break;
            case 'R':
                dirIndex = (dirIndex + 3) % 4;
                break;
            default:
                break;
        }
        
        int nx = x + dx[dirIndex];
        int ny = y + dy[dirIndex];
        optimizeCoord(nx, ny);
        
        if (field[nx][ny][dirIndex] == false) {
            field[nx][ny][dirIndex] = true;
            que.push(ThreePair(nx, ny, dirIndex));
            cycleLength += 1;
        }
    }
    
    answer.push_back(cycleLength);
}

void optimizeCoord(int& nx, int& ny) {
    if (nx < 0) nx += rowLen;
    else if (nx >= rowLen) nx -= rowLen;
    
    if (ny < 0) ny += columnLen;
    else if (ny >= columnLen) ny -= columnLen;
}
