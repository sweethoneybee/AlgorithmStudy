//
//  월코테2문제1.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/13.
//

#include <string>
#include <vector>

using namespace std;

int countDivisor(const int n) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if (n % i == 0) count += 1;
    }
    return count;
}
int solution(int left, int right) {
    int answer = 0;
    for(int n = left; n <= right; n++) {
        int divisor = countDivisor(n);
        if (divisor % 2 == 0) answer += n;
        else answer -= n;
    }
    return answer;
}
