//
//  1747.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/23.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrom(const int prime);
void relax(vector<bool>& numbers, const int prime);

int main(void) {
    int N;
    cin >> N;
    
    vector<bool> numbers(10000001, true);
    int answer = 0;
    for(int i = 2; i <= 10000000; i++) {
        if (numbers[i] == false) {
            continue;
        }
        
        if (i >= N && isPalindrom(i)) {
            answer = i;
            break;
        }
        
        relax(numbers, i);
    }
    
    cout << answer;
    return 0;
}

bool isPalindrom(int prime) {
    if (prime < 10) {
        return true;
    }
    
    string strPrime = to_string(prime);
    
    int leftSide = 0;
    int rightSide = strPrime.length() - 1;
    while(leftSide < rightSide) {
        if (strPrime[leftSide] != strPrime[rightSide]) {
            return false;
        }
        leftSide += 1;
        rightSide -= 1;
    }
    return true;
}

void relax(vector<bool>& numbers, const int prime) {
    int times = 2;
    int primeTimes = prime * times;
    const auto size = numbers.size();
    while(primeTimes < size) {
        numbers[primeTimes] = false;
        times += 1;
        primeTimes = prime * times;
    }
}
