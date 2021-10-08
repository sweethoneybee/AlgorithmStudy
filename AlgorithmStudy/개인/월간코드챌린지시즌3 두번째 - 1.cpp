//
//  월간코드챌린지시즌3 두번째 - 1.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/07.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i < n; i++) {
        if(n % i == 1) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
