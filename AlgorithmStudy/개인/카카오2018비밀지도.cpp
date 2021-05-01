//
//  카카오2018비밀지도.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/01.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toBit(const int n, int code) {
    string bit = "";
    while(code > 0) {
        bit = (code % 2 == 0 ? "0" : "1") + bit;
        code /= 2;
    }
    
    if (bit.length() < n) bit = string(n - bit.length(), '0') + bit;
    return bit;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        string leftMap = toBit(n, arr1[i]);
        string rightMap = toBit(n, arr2[i]);
        
        string line = "";
        for(int j = 0; j < n; j++) {
            line += ((leftMap[j] == '1' || rightMap[j] == '1') ? "#" : " ");
        }
        answer.push_back(line);
    }
    return answer;
}

int main(void) {
    int temp = 33;
    cout << toBit(10, temp) << endl;
    
    int a = 9;
    int b = 7;
    int result = a&b;
    cout << result << endl;
    return 0;
}
