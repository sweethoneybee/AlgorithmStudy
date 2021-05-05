//
//  카카오2021신규아이디추천.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/05.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(string new_id) {

    string id = new_id;
    int len = 0;
    // 1. 대문자 to 소문자
    len = id.length();
    for(int i = 0; i < len; i++) {
        id[i] = tolower(id[i]);
    }
    
    // 2. 소문자, 숫자, -, _, . 외 제거
    len = id.length();
    for(int i = 0; i < len; i++) {
        const char c = id[i];
        
        if ((c < 'a' || c > 'z')
            && (c < '0' || c > '9')
            && (c != '-')
            && (c != '_')
            && (c != '.')) {
            id.erase(id.begin() + i);
            i -= 1;
            len = id.length();
        }
    }
    
    // 3. 마침표 2번 이상
    len = id.length();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        const char c = id[i];
        if (c == '.') cnt += 1;
        else if (cnt >= 2) {
            id.erase(id.begin() + (i - cnt), id.begin() + (i - 1));
            len = id.length();
            i = i - cnt + 1;
            cnt = 0;
        } else cnt = 0;
    }
    if (cnt >= 2) id.erase(id.begin() + (id.length() - cnt), id.end());
    
    // 4. 마침표 처음, 끝 제거
    if (id.front() == '.') id.erase(id.begin());
    if (id.back() == '.') id.pop_back();
    
    // 5. 빈문자열인 경우
    if (id == "") id += "a";
    
    // 6. 길이가 16보다 긴 경우
    if (id.length() >= 16) id = id.substr(0, 15);
    if (id.back() == '.') id.pop_back();
    
    // 7. 길이가 2보다 작은 경우
    while (id.length() <= 2) {
        id.push_back(id.back());
    }
    
    return id;
}

int main(void) {
    string id = "abcdefg_-+-";
    cout << solution(id) << endl;
    return 0;
}
