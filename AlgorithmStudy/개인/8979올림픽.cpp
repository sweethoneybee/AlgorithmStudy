//
//  8979올림픽.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    int number;
    vector<int> input(3);
    vector<pair<int, vector<int>>> nation;
    for(int i = 0; i < N ; i++) {
        cin >> number >> input[0] >> input[1] >> input[2];
        nation.push_back(make_pair(number, input));
    }
    
    sort(nation.begin(), nation.end(), [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b)->bool {
        const auto& medalA = a.second;
        const auto& medalB = b.second;
        
        if (medalA[0] != medalB[0]) return medalA[0] > medalB[0];
        else if(medalA[1] != medalB[1]) return medalA[1] > medalB[1];
        else return medalA[2] > medalB[2];
    });
    
    number = 0;
    for(int i = 0; i < N; i++) {
        if (nation[i].first == K) {
            number = i;
            break;
        }
    }
    
    int count = 0;
    const auto& targetScore = nation[number].second;
    for(int i = number - 1; i >= 0; i--) {
        const auto& compare = nation[i].second;
        if (targetScore[0] == compare[0]
            && targetScore[1] == compare[1]
            && targetScore[2] == compare[2]) {
            count += 1;
            continue;
        }
        break;
    }
    
    cout << number + 1 - count;
    
    return 0;
}
