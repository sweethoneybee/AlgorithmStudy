//
//  3048개미.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N1, N2;
    cin >> N1 >> N2;
    vector<pair<char, int>> antLeft, antRight;
    
    string input;
    cin >> input;
    int index = 1;
    for(int i = N1 - 1; i >= 0; i--) {
        antLeft.push_back(make_pair(input[i], index));
        index += 2;
    }
    index -= 1;
    cin >> input;
    for(int i = 0; i < N2; i++) {
        antRight.push_back(make_pair(input[i], index));
        index += 2;
    }
    
    int T;
    cin >> T;
    
    for(auto& ant: antLeft) ant.second += T;
    for(auto& ant: antRight) ant.second -= T;
    vector<pair<char, int>> answer = antLeft;
    answer.insert(answer.end(), antRight.begin(), antRight.end());
    
    sort(answer.begin(), answer.end(), [](const pair<char, int>& a, const pair<char, int>& b)->bool {
        return a.second < b.second;
    });
    
    for(const auto& ant: answer) cout << ant.first;
    
    return 0;
}
