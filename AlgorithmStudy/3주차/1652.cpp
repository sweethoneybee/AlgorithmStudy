//
//  1652.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<string> room;
    for(int i = 0; i < N; i++) {
        string line;
        cin >> line;
        room.push_back(line);
    }
    
    int canLieRow = 0;
    for(const auto& row: room) {
        int spaceCount = 0;
        for(int i = 0, len = row.length(); i < len; i++) {
            if (row[i] == '.') {
                spaceCount += 1;
            } else {
                spaceCount = 0;
            }
            
            if (spaceCount >= 2) {
                canLieRow += 1;
                while(i + 1 < len) {
                    i += 1;
                    if (row[i] == 'X') {
                        spaceCount = 0;
                        break;
                    }
                }
            }
        }
    }
    
    int canLieColumn = 0;
    for(int i = 0, size = room.size(); i < size; i++) {
        int spaceCount = 0;
        for(int j = 0; j < size; j++) {
            if (room[j][i] == '.') {
                spaceCount += 1;
            } else {
                spaceCount = 0;
            }
            
            if (spaceCount >= 2) {
                canLieColumn += 1;
                while(j + 1 < size) {
                    j += 1;
                    if (room[j][i] == 'X') {
                        spaceCount = 0;
                        break;
                    }
                }
            }
        }
    }
    
    cout << canLieRow << " " << canLieColumn;
    return 0;
}

