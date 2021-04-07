//
//  1205.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/07.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, S, P;
    cin >> N >> S >> P;
    
    vector<int> scores;
    for(int i = 0; i < N; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }
    
    if (scores.size() == 0) {
        cout << 1;
    } else if (scores.size() == P && scores.back() >= S) {
        cout << -1;
    } else {
        int index = 0;
        for(; index < N; index++) {
            if (scores[index] <= S) {
                break;
            }
        }
        cout << index + 1;
    }
    return 0;
}
