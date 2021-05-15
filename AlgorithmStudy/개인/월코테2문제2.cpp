//
//  월코테2문제2.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/13.
//

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int countRightBit(long long n) {
    int cnt = 0;
    while(n) {
        if (n & 1 == 1) cnt += 1;
        else break;
        n = n >> 1;
    }
    return cnt;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
        
    for(const auto& n: numbers) {
        int first = (n & (1 << 1)) >> 1; // 우측에서 1번째 비트
        int second = n & 1; // 우측에서 0 번째 비트
        if ((first & second) == 0) {
            answer.push_back(n + 1);
        } else {
            int cnt = countRightBit(n);
            answer.push_back(n + pow(2, cnt - 1));
        }
    }
    return answer;
}
