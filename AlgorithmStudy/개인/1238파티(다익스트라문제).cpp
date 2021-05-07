//
//  1238파티(다익스트라문제).cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/07.
//


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 999999999;
int N, M, X;

int dijkstra(const int s, const int x, const vector<vector<pair<int, int>>>& path) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, MAX);
    dist[s] = 0;
    pq.push(make_pair(dist[s], s));
    while(!pq.empty()) {
        int from = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(const auto& adj: path[from]) {
            int to = adj.second;
            int nCost = adj.first;
            
            if (dist[to] > cost + nCost) { // relax
                dist[to] = cost + nCost;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
    
    int ret = dist[x];
    return ret;
}

int main(void) {
    cin >> N >> M >> X;
    vector<vector<pair<int, int>>> path(N + 1);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back(make_pair(c, b)); // from a, to b, distance c
    }
    
    int result = -1;
    for(int i = 1; i <= N; i++) {
        int value = dijkstra(i, X, path) + dijkstra(X, i, path);
        if (result < value) result = value;
    }
    cout << result;
    return 0;
}
