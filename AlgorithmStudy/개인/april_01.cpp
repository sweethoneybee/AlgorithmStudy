//
//  april_01.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/15.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    
    int sum = 0;
    int size = absolutes.size();
    for(int i = 0; i < size; i++) {
        if (signs[i]) {
            sum += absolutes[i];
        } else {
            sum -= absolutes[i];
        }
    }
    answer = sum;
    return answer;
}
