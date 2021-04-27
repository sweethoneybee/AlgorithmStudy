//
//  카카오2020괄호변환.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/27.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int divideCount(const string& s) {
    int front = 0, back = 0;
    if (s.front() == '(') front += 1;
    else if (s.front() == ')') back += 1;
    
    for(int i = 1, len = s.length(); i < len; i++) {
        if (s[i] == '(') front += 1;
        else if (s[i] == ')') back += 1;
        if (front == back) break;
    }
    
    return front + back;
}

bool isValidStr(const string& s) {
    stack<char> b;
    
    for(auto parentheses: s) {
        if (parentheses == '(') b.push(parentheses);
        else if (parentheses == ')') {
            if (b.empty()) return false;
            b.pop();
        }
    }
    return b.empty();
}

string reverseParentheses(const string& s) {
    string ret = "";
    for(const auto p: s) {
        if (p == '(') ret.push_back(')');
        else if (p == ')') ret.push_back('(');
    }
    return ret;
}

string recursion(string arg) {
    if (arg.empty()) return arg;
    
    int m = divideCount(arg);
    string u = arg.substr(0, m);
    string v = m >= arg.length() ? "" : arg.substr(m);
    if (isValidStr(u)) return u + recursion(v);
    
    u = u.length() == 2 ? "" : u.substr(1, u.length() - 2);
    return "(" + recursion(v) + ")" + reverseParentheses(u);
}

string solution(string p) {
    if (isValidStr(p)) return p;
    
    string answer = recursion(p);
    return answer;
}


int main(void) {
    string p = "1234";
    cout << solution(p) << endl;
    
    return 0;
}
