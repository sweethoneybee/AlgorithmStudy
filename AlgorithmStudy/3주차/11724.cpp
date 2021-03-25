//
//  11724.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& vertexes, vector<bool>& foundFlag, int startVertex);
void bfs(const vector<vector<int>>& vertexes, vector<bool>& foundFlag, int startVertex) {
    queue<int> que;
    que.push(startVertex);
    foundFlag[startVertex] = true;
    
    while(que.empty() != true) {
        int v = que.front();
        que.pop();
        
        for(const auto& adj: vertexes[v]) {
            if (foundFlag[adj] == true) {
                continue;
            }
            
            que.push(adj);
            foundFlag[adj] = true;
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vertexes(N);
    
    for(int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1 -= 1;
        v2 -= 1;
        
        vertexes[v1].push_back(v2);
        vertexes[v2].push_back(v1);
    }
    
    int count = 0;
    vector<bool> foundFlag(N, false);
    for(int vertexNumber = 0; vertexNumber < N; vertexNumber++) {
        if (foundFlag[vertexNumber] == true) {
            continue;
        }
        
        count += 1;
        bfs(vertexes, foundFlag, vertexNumber);
    }
    
    cout << count;
    return 0;
}
