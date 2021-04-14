//
//  17135.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/14.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int simulate(const vector<vector<int>>& board, const int archerRange, const int enemyCount);
int playGame(vector<vector<int>> board, const vector<int>& possibleArcherColumn, const int archerRange, const int enemyCount);
int killEnemy(vector<vector<int>>& board, const vector<pair<int, int>>& archers, const int archerRange, const int row);
bool isVaild(int x, int y, int maxX, int maxY);

int main(void) {
    int N, M, D;
    cin >> N >> M >> D;
    
    vector<vector<int>> board(N, vector<int>(M, 0));
    int enemyCount = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int enemy;
            cin >> enemy;
            board[i][j] = enemy;
            if (enemy == 1) {
                enemyCount += 1;
            }
        }
    }
    
    int answer = simulate(board, D, enemyCount);
    cout << answer;
    
    return 0;
}

int simulate(const vector<vector<int>>& board, const int archerRange, const int enemyCount) {
    vector<int> possibleArcherColumn(3, 0);
    int totalKillCount = 0;
    int canArcherStandColumn = board.front().size();
    for(int a = 0; a < canArcherStandColumn; a++) {
        possibleArcherColumn[0] = a;
        for(int b = a + 1; b < canArcherStandColumn; b++) {
            possibleArcherColumn[1] = b;
            for(int c = b + 1; c < canArcherStandColumn; c++) {
                possibleArcherColumn[2] = c;
                
                int result = playGame(board, possibleArcherColumn, archerRange, enemyCount);
                if (result > totalKillCount) {
                    totalKillCount = result;
                }
            }
        }
    }
    
    return totalKillCount;
}

int playGame(vector<vector<int>> board, const vector<int>& possibleArcherColumn, const int archerRange, const int enemyCount) {
    int totalKillCount = 0;
    for(int row = board.size(); row > 0; row--) {
        vector<pair<int, int>> archers;
        for(const auto& archerColumn: possibleArcherColumn) {
            archers.push_back(make_pair(row, archerColumn));
        }
       
        int killedEnemy = killEnemy(board, archers, archerRange, row);
        totalKillCount += killedEnemy;
        
        if (totalKillCount >= enemyCount) {
            break;
        }
    }
    return totalKillCount;
}

int killEnemy(vector<vector<int>>& board, const vector<pair<int, int>>& archers, const int archerRange, const int row) {
    set<pair<int, int>> targetEnemy;
    
    for(const auto& archer: archers) {
        queue<pair<int, int>> que;
        queue<int> currentRange;
        set<pair<int, int>> hasPeeked;
        
        que.push(archer);
        currentRange.push(0);
        hasPeeked.insert(archer);
        
        int dx[] = {0, -1, 0};
        int dy[] = {-1, 0, 1};
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            int range = currentRange.front();
            currentRange.pop();
            
            if (range + 1 > archerRange) {
                break;
            }
            
            bool foundFlag = false;
            for(int i = 0; i < 3; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx == archer.first
                    || !isVaild(nx, ny, board.size() - 1, board.front().size() - 1)
                    || hasPeeked.find(make_pair(nx, ny)) != hasPeeked.end()) {
                    continue;
                }
            
                if (board[nx][ny] == 1) {
                    targetEnemy.insert(make_pair(nx, ny));
                    foundFlag = true;
                    break;
                } else {
                    que.push(make_pair(nx, ny));
                    currentRange.push(range + 1);
                    hasPeeked.insert(make_pair(nx, ny));
                }
            }
            if (foundFlag) {
                break;
            }
        }
    }
    
    for(const auto& killedEnemy: targetEnemy) {
        int x = killedEnemy.first;
        int y = killedEnemy.second;
        board[x][y] = 0;
    }
    
    return targetEnemy.size();
}

bool isVaild(int x, int y, int maxX, int maxY) {
    if (x >= 0 && x <= maxX && y >= 0 && y <= maxY) {
        return true;
    } else {
        return false;
    }
}
