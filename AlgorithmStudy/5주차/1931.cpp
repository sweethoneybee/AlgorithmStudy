//
//  1931.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<pair<int, int>> meetings;
    for(int i = 0; i < N; i++) {
        int s, f;
        cin >> s >> f;
        meetings.push_back(make_pair(s, f));
    }
    
    sort(meetings.begin(),
         meetings.end(),
[](const pair<int, int>& a, const pair<int, int>& b)->bool{
        if (a.second < b.second) {
            return true;
        } else if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return false;
        }
    }
         );
    
    int usingF = -1;
    int count = 0;
    for(const auto& meet: meetings) {
        const auto& start = meet.first;
        if (start >= usingF) {
            const auto& finish = meet.second;
            usingF = finish;
            count += 1;
        }
    }
    
    cout << count;
    return 0;
}
