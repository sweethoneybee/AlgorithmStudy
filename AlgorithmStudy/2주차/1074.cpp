//
//  1074.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/18.
//

#include <iostream>
#include <cmath>
using namespace std;

int getCountInSquare(int n);
int divideAndConquer(int n, int count, int r, int c);

int getCountInSquare(int n) {
    return pow(2, n + n - 2);
}

int divideAndConquer(int n, int count, int r, int c) {
    if ( n <= 0 ) {
        return count;
    }
    
    const int lineCount = pow(2, n);
    if (r < lineCount / 2) {
        if (c < lineCount / 2) {
            return divideAndConquer(n - 1, count, r, c);
        } else {
            return divideAndConquer(n - 1, count + getCountInSquare(n), r, c - lineCount / 2);
        }
    } else {
        if (c < lineCount / 2) {
            return divideAndConquer(n - 1, count + getCountInSquare(n) * 2, r - lineCount / 2, c);
        }
        else {
            return divideAndConquer(n - 1, count + getCountInSquare(n) * 3, r - lineCount / 2, c - lineCount / 2);
        }
    }
}

int main(void) {
    int N, r, c = 0;
    cin >> N >> r >> c;
    
    int result = divideAndConquer(N, 0, r, c);
    cout << result;
    
    return 0;
}
