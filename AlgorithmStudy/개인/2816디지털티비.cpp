//
//  2816디지털티비.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/12.
//

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int N, one, two;
    string input;
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> input;
        if (input == "KBS1") one = i;
        if (input == "KBS2") two = i;
    }
    
    if (one > two) {
        for (int i = 0; i < two; ++i) cout << 1;
        for (int i = 0; i < two; ++i) cout << 4;
        for (int i = 0; i < one; ++i) cout << 1;
        for (int i = 0; i < one; ++i) cout << 4;
    } else {
        for (int i = 0; i < one; ++i) cout << 1;
        for (int i = 0; i < one; ++i) cout << 4;
        for (int i = 0; i < two; ++i) cout << 1;
        for (int i = 0; i < two - 1; ++i) cout << 4;
    }
    return 0;
}
