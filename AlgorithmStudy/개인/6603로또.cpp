//
//  6603로또.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void pick(const vector<int>& numbers, vector<int>& pool, const int start) {
    if (pool.size() >= 6) {
        for(const auto& p: pool) {
            cout << p << " ";
        }
        cout << endl;
    } else {
        for(int i = start, size = numbers.size(); i < size; ++i) {
            pool.push_back(numbers[i]);
            pick(numbers, pool, i + 1);
            pool.pop_back();
        }
    }
}
int main(void) {
    int k, input;
    
    while(true) {
        cin >> k;
        if (k == 0) break;
        
        vector<int> numbers(k);
        for(int i = 0; i < k; i++) {
            cin >> input;
            numbers[i] = input;
        }
        
        sort(numbers.begin(), numbers.end());
        vector<int> pool;
        pick(numbers, pool, 0);
        cout << endl;
    }
    
    return 0;
}

