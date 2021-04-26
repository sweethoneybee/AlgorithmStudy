//
//  카카오2019실패율.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/26.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> users(N + 2, 0);
    
    for(const auto s: stages) {
        users[s] += 1;
    }
    
    vector<pair<double, int>> ratios;
    double reach = users[N + 1] + users[N];
    double failed = users[N];
    double r = reach == 0 ? 0 : failed / reach;
    ratios.push_back(make_pair(r, N));
    
    for(int i = N - 1; i >= 1; i--) {
        reach += users[i];
        failed = users[i];
        r = reach == 0 ? 0 : failed / reach;
        ratios.push_back(make_pair(r, i));
    }
    
    sort(ratios.begin(), ratios.end(), [](const pair<double, int>& a, const pair<double, int>& b)->bool{
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    for(const auto& e: ratios) {
        answer.push_back(e.second);
    }
    
    return answer;
}


int main(void) {
    
    return 0;
}
