//
//  1.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/15.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void select(const vector<int>& money, int n, int start, int& answer) {
    for(int i = start, size = money.size(); i < size; i++) {
        int m = money[i];
        if (m > n) {
            return; // money must be sorted
        }
        
        int moc = n / m;
        for(int mul = moc; mul > 0; mul--) {
            int remainder = n - (m * mul);
            if (remainder == 0) {
                answer += 1;
                answer %= 1000000007;
            } else {
                select(money, remainder, i + 1, answer);
            }
        }
    }
}

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(), money.end());
    select(money, n, 0, answer);
    return answer;
}

int main(void) {
    int n = 10000;
    vector<int> money = {1, 2, 5};
    cout << solution(n, money) << endl;
    return 0;
}
