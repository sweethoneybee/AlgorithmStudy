//
//  10773제로.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/13.
//

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int K, input, sum;
    stack<int> s;
    
    cin >> K;
    sum = 0;
    for(int i = 0; i < K; ++i) {
        cin >> input;
        
        if (input == 0) {
            sum -= s.top();
            s.pop();
        } else {
            sum += input;
            s.push(input);
        }
    }
    cout << sum;
    return 0;
    // 너무... 바빠... OTL
}
