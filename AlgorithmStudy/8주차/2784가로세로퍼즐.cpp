//
//  2784가로세로퍼즐.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/19.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    vector<string> words(6);
    for(int i = 0; i < 6; i++) cin >> words[i];
    
    vector<vector<string>> answer;
    do {
        vector<string> board(3);
        for(int i = 0; i < 3; i++) board[i] = words[i];
        
        string a, b, c;
        a = board[0].substr(0, 1) + board[1].substr(0, 1) + board[2].substr(0, 1);
        b = board[0].substr(1, 1) + board[1].substr(1, 1) + board[2].substr(1, 1);
        c = board[0].substr(2, 1) + board[1].substr(2, 1) + board[2].substr(2, 1);
        
        if (a == words[3] && b == words [4] && c == words[5]) answer.push_back(board);
        
    } while(next_permutation(words.begin(), words.end()));
    
    if (answer.empty()) cout << 0;
    else {
        for(const auto& s: answer.front()) cout << s << endl;
    }
    
    return 0;
}
