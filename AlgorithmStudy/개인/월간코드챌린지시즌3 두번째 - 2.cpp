//
//  월간코드챌린지시즌3 두번째 - 2.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/07.
//

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int leftMock, leftRemainder, rightMock, rightRemainder;
    leftMock = left / n;
    leftRemainder = left % n;
    rightMock = right / n;
    rightRemainder = right % n;
    
    if(leftMock == rightMock) {
        for(int i = leftRemainder; i <= rightRemainder; i++) {
            if(i <= leftMock) {
                answer.push_back(leftMock + 1);
                continue;
            }
            answer.push_back(i + 1);
        }
        
        return answer;
    }
    
    // first row
    for(int i = leftRemainder; i < n; i++) {
        if(i <= leftMock) {
            answer.push_back(leftMock + 1);
            continue;
        }
        answer.push_back(i + 1);
    }
    
    // middle row
    for(int i = leftMock + 1; i < rightMock; i++) {
        for(int j = 0; j<= i; j++) {
            answer.push_back(i + 1);
        }
        for(int j = i + 1; j < n; j++) {
            answer.push_back(j + 1);
        }
    }

    // last row
    for(int i = 0; i <= rightRemainder; i++) {
        if(i <= rightMock) {
            answer.push_back(rightMock + 1);
            continue;
        }
        answer.push_back(i + 1);
    }
    return answer;
}
