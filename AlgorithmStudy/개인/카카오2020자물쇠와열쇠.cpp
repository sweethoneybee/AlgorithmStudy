//
//  카카오2020자물쇠와열쇠.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/03.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotateKeyToRight(const vector<vector<int>>& key, const int count) {
    if (count == 0) return key;
    
    int size = key.size();
    vector<vector<int>> ret = key;
    for(int c = 0; c < count; c++) {
        vector<vector<int>> sample = ret;
        for(int i = 0; i < size; i++) {
            int k = size - 1;
            for(int j = 0; j < size; j++) {
                ret[i][j] = sample[k][i];
                k -= 1;
            }
        }
    }
    return ret;
}

bool isVaildCoord(int x, int y) {
    return (x >= 0) && (y >= 0);
}

void updateKey(vector<vector<int>>& key, int dx, int dy) {
    int size = key.size();
    int nx, ny;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (key[i][j] == 1) {
                key[i][j] = 0;
                nx = i - dx;
                ny = j - dy;
                if (isVaildCoord(nx, ny)) {
                    key[nx][ny] = 1;
                }
            }
        }
    }
}

bool isFitKey(const vector<vector<int>>& key, const vector<vector<int>>& lock) {
    int lockSize = lock.size();
    int hole;
    for(int i = 0; i < lockSize; i++) {
        for(int j = 0; j < lockSize; j++) {
            hole = lock[i][j] + key[i][j];
            if (hole == 0 || hole == 2) return false;
        }
    }
    return true;
}

bool canBeAnswerKey(const vector<vector<int>> key, const vector<vector<int>>& lock) {
    int keyCount = 0, lockCount = 0;
    for(const auto& line: key) {
        for (const auto& value: line) {
            if (value == 1) keyCount += 1;
        }
    }
    for(const auto& line: lock) {
        for (const auto& value: line) {
            if (value == 0) lockCount += 1;
        }
    }
    
    return keyCount > lockCount;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    if (canBeAnswerKey(key, lock) == false) return false;
    
    int keySize = key.size(), lockSize = lock.size();
    // try 4 rotated key
    for(int r = 0; r < 4; r++) {
        vector<vector<int>> rotatedKey = rotateKeyToRight(key, r);
        vector<vector<int>> originalTrialKey(keySize + lockSize, vector<int>(keySize + lockSize, 0));
        for(int i = 0; i < keySize; i++) {
            for(int j = 0; j < keySize; j++) {
                originalTrialKey[i + lockSize][j + lockSize] = rotatedKey[i][j];
            }
        }
        
        // brute force
        for(int dx = 1; dx < lockSize * 2 - 1; dx++) {
            vector<vector<int>> trialKey = originalTrialKey;
            updateKey(trialKey, dx, 0);
            for(int i = 0; i < lockSize * 2 - 1; i++) {
                updateKey(trialKey, 0, 1);
                if (isFitKey(trialKey, lock)) return true;
            }
        }
    }
    
    return false;
}

int main(void) {
    cout << "wow" << endl;
    return 0;
}
