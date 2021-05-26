//
//  2644촌수계산.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/26.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(const vector<vector<int>>& people, const int start, const int target) {
    queue<pair<int, int>> que;
    que.push(make_pair(start, 0));
    vector<bool> flag(people.size(), false);
    flag[start] = true;
    
    while(!que.empty()) {
        int from = que.front().first;
        int count = que.front().second;
        que.pop();
        
        for(const int adj: people[from]) {
            if (adj == target)
                return count + 1;
            if (flag[adj])
                continue;
            que.push(make_pair(adj, count + 1));
            flag[adj] = true;
        }
    }
    
    return -1;
}

int main(void) {
    int N, from, to, m, x, y;
    cin >> N >> from >> to >> m;
    
    vector<vector<int>> people(N + 1);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        people[x].push_back(y);
        people[y].push_back(x);
    }
    cout << bfs(people, from, to);
    return 0;
}
