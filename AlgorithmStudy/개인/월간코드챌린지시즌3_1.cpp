//
//  월간코드챌린지시즌3_1.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/09.
//

#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> numbers) {
    set<int> s;
    for (int i = 0; i < 10; i++) {
        s.insert(i);
    }
    
    for (const auto n: numbers) {
        s.erase(n);
    }
    
    int answer = 0;
    for (const auto num: s) {
        answer += num;
    }
    return answer;
}
