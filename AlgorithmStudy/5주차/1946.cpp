//
//  1946.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int testCase();
int findJunior(const vector<pair<int, int>>& applicants);

int testCase() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> applicants;
    for(int i = 0; i < N; i++) {
        int paper, interview;
        cin >> paper >> interview;
        applicants.push_back(make_pair(paper, interview));
    }
    
    sort(applicants.begin(), applicants.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool {
        return a.first < b.first;
    });
    
    return findJunior(applicants);
}

int findJunior(const vector<pair<int, int>>& applicants) {
    int count = 0;
    int highRank = 100001;
    
    for(const auto& ap: applicants) {
        if (ap.second < highRank) {
            count += 1;
            highRank = ap.second;
        }
    }
    return count;
}

int main(void) {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cout << testCase() << endl;
    }
    return 0;
}
