//
//  1476날짜계산.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/15.
//

#include <iostream>
using namespace std;

int main(void) {
    const int MAX_E = 15, MAX_S = 28, MAX_M = 19;
    int E, S, M;
    cin >> E >> S >> M;
    
    int year = 1, e = 1, s = 1, m = 1;
    while(true) {
        if (e == E && s == S && m == M) break;
        year += 1;
        if (++e > MAX_E) e = 1;
        if (++s > MAX_S) s = 1;
        if (++m > MAX_M) m = 1;
    }
    
    cout << year;
    // 며칠만 더... 조금만 더...
    return 0;
}
