//
//  프린터.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void updateMostPriority(const vector<int>& memo, int& mostPriority) {
    for(int i = mostPriority; i >= 1; i--) {
        if (memo[i] > 0) {
            mostPriority = i;
            return;
        }
    }
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> que;
    vector<int> memo(10, 0);
    int mostPriority = 0;
    for(const auto p: priorities) {
        que.push(p);
        memo[p] += 1;
        if (mostPriority < p) {
            mostPriority = p;
        }
    }
    
    int order = location;
    int printCount = 0;
    while(!que.empty()) {
        int frontPriority = que.front();
        que.pop();
        if (frontPriority >= mostPriority) { // did print
            printCount += 1;
            if (order == 0) {
                break;
            } else {
                order -= 1;
                memo[frontPriority] -= 1;
                updateMostPriority(memo, mostPriority);
            }
        } else {
            que.push(frontPriority);
            if (order == 0) {
                order += que.size() - 1;
            } else {
                order -= 1;
            }
        }
    }
    
    answer = printCount;
    return answer;
}

int main(void) {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    cout << solution(priorities, location) << endl;
    return 0;
}
