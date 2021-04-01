//
//  1260.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/01.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(const vector<vector<int>>& vertexes, vector<bool>& flag, int start);
void dfs(const vector<vector<int>>& vertexes, vector<bool>& flag, int from);

void bfs(const vector<vector<int>>& vertexes, vector<bool>& flag, int start) {
    queue<int> que;
    
    que.push(start);
    flag[start] = true;
    
    cout << start + 1 << " ";
    while(que.empty() != true) {
        int from = que.front();
        que.pop();
        
        for(const auto& to: vertexes[from]) {
            if (flag[to] == true)
                continue;
            
            cout << to + 1 << " ";
            que.push(to);
            flag[to] = true;
        }
    }
}

void dfs(const vector<vector<int>>& vertexes, vector<bool>& flag, int from) {
    cout << from + 1 << " ";
    for(const auto& to: vertexes[from]) {
        if (flag[to] == true)
            continue;
        
        flag[to] = true;
        dfs(vertexes, flag, to);
    }
}

int main(void) {
    int N, M, V;
    cin >> N >> M >> V;
    
    vector<vector<int>> vertexes(N);
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        vertexes[from - 1].push_back(to - 1);
        vertexes[to - 1].push_back(from - 1);
    }
    
    for(int i = 0; i < N; i++) {
        sort(vertexes[i].begin(), vertexes[i].end());
    }
    
    vector<bool> flag(N, false);
    flag[V - 1] = true;
    dfs(vertexes, flag, V - 1);
    cout << endl;
    vector<bool> flagForBfs(N, false);
    bfs(vertexes, flagForBfs, V - 1);
    return 0;
}
