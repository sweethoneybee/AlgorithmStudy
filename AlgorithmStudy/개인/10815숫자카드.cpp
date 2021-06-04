//
//  10815숫자카드.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/05.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    int N, M, input;
    cin >> N;
    set<int> sang;
    for(int i = 0; i < N; ++i) {
        cin >> input;
        sang.insert(input);
    }
    
    cin >> M;
    vector<int> cards(M);
    vector<bool> check(M, false);
    for(int i = 0; i < M; ++i) {
        cin >> input;
        cards[i] = input;
    }
    
    for(int i = 0; i < M; ++i) {
        const auto& number = cards[i];
        if (sang.find(number) != sang.end()) check[i] = true;
    }
    
    for(const auto c: check) {
        cout << c << " ";
    }
    return 0;
}
