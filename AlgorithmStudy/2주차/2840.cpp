//
//  2840.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/19.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    
    int numberOfBlocks = N;
    
    vector<char> circle(N, '?');
    vector<bool> didFound(26, false);
    vector<pair<int, char>> paper;
    for(int i = 0; i < K; i++) {
        int changed;
        char alpha;
        
        cin >> changed >> alpha;
        paper.push_back(make_pair(changed, alpha));
    }
    
    bool makeSense = true;
    int startIndex = 0;
    
    for(const auto& item: paper) {
        const int& changed = item.first;
        const char& alpha = item.second;
        
        int next = (startIndex + changed) % numberOfBlocks;
        if (circle[next] != '?') {
            if (circle[next] != alpha) {
                makeSense = false;
                break;
            }
        } else if (didFound[alpha - 'A'] == true) {
            makeSense = false;
            break;
        }
        
        circle[next] = alpha;
        didFound[alpha - 'A'] = true;
        startIndex = next;
    }
    
    if (makeSense) {
        for(int i = 0, size = circle.size(); i < size; i++) {
            cout << circle[startIndex];
            startIndex -= 1;
            if (startIndex < 0) {
                startIndex = size - 1;
            }
        }
    } else {
        cout << "!";
    }
    return 0;
}
