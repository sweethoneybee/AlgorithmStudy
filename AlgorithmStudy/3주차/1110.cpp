//
//  1110.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/22.
//

#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    const int originalNum = N;
    int oldNum = N;
    int newNum = 0;
    int count = 0;
    do {
        count += 1;
        
        if (oldNum < 10) {
            newNum = (oldNum * 10) + oldNum;
        } else {
            int digitSum = (oldNum / 10) + (oldNum % 10);
            newNum = (oldNum % 10 * 10) + (digitSum % 10);
        }
        
        oldNum = newNum;
    } while (originalNum != newNum);
    
    cout << count;
    return 0;
}
