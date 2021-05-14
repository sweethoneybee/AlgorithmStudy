//
//  1026보물.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, input;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> input;
        A[i] = input;
    }
    for(int i = 0; i < N; i++) {
        cin >> input;
        B[i] = input;
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](const int a, const int b)->bool {
        return a > b;
    });
    
    int answer = 0;
    for(int i = 0; i < N; i++) answer += (A[i] * B[i]);
    cout << answer;
    
    return 0;
}
