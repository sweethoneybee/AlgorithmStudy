//
//  2309 일곱난쟁이.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> answer;

void combi(const vector<int>& smalls, vector<int>& pick, int start) {
    if (pick.size() >= 7) {
        int sum = 0;
        for(const auto p: pick) sum += p;
        if (sum == 100) answer = pick;
    } else {
        for(int i = start; i < smalls.size(); i++) {
            pick.push_back(smalls[i]);
            combi(smalls, pick, i + 1);
            pick.pop_back();
        }
    }
}

int main(void) {
    vector<int> smalls(9, 0);
    for(int i = 0; i < 9; i++) cin >> smalls[i];
    
    vector<int> pick;
    combi(smalls, pick, 0);
    
    sort(answer.begin(), answer.end());
    for(const auto a: answer) cout << a << endl;
    return 0;
}
