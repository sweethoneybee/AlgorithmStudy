//
//  april_02.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/15.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//[](){}
int solution(string s) {
    int answer = 0;
    
    int i = 0;
    int len = s.length();
    if (len == 1) {
        return answer;
    }
    while (i < len) {
        stack<char> brakets;
        bool flag = true;
        for(const auto c: s) {
            if (c == '[' || c == '{' || c == '(') {
                brakets.push(c);
            } else if (brakets.size() == 0) {
                flag = false;
                break;
            } else {
                char braket = brakets.top();
                brakets.pop();
                
                if (!((braket == '[' && c == ']')
                    || (braket == '{' && c == '}')
                    || (braket == '(' && c == ')'))) {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag && brakets.size() == 0) {
            answer += 1;
        }
        s.push_back(s.front());
        s.erase(s.begin());
        i += 1;
    }
    return answer;
}

int main(void) {
    string s = "{";
    cout << solution(s);
    return 0;
}
