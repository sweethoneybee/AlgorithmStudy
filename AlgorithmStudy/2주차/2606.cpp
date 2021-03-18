//
//  2606.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/18.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(const vector<vector<int>>& computers, int startNumber) {
    vector<bool> foundFlag(computers.size(), false);
    queue<int> que;
    
    foundFlag[startNumber] = true;
    que.push(startNumber);
    
    int count = 0;
    while(que.empty() != true) {
        const vector<int>& infectedComputer = computers[que.front()];
        que.pop();
        
        for(const auto& nearByComputerNumber: infectedComputer) {
            if (foundFlag[nearByComputerNumber] == true) {
                continue;
            }
            
            foundFlag[nearByComputerNumber] = true;
            count += 1;
            que.push(nearByComputerNumber);
        }
    }
    
    return count;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> computers(N);
    
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        
        from -= 1;
        to -= 1;
        
        computers[from].push_back(to);
        computers[to].push_back(from);
    }
    
    int result = bfs(computers, 0);
    
    cout << result;
    return 0;
}
