//
//  카카오2019후보키.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/30.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<set<int>> candidateKeys;

set<int> vecToSet(const vector<int>& v) {
    set<int> s;
    for(const auto& item: v) {
        s.insert(item);
    }
    return s;
}

bool isPossibleKey(const vector<vector<string>>& relation, const vector<int>& possibleKey) {
    set<string> s;
    int rowSize = relation.size();
    for(int i = 0; i < rowSize; i++) {
        string att = "";
        for(const auto& key: possibleKey) {
            att += relation[i][key] + "&";
        }
        s.insert(att);
    }
    
    if (s.size() == rowSize) return true;
    return false;
}

bool canBeCandidateKey(const set<int>& keyPool) {
    for(const auto& key: candidateKeys) {
        int cnt = 0;
        for(const auto& att: key) {
            if (keyPool.find(att) != keyPool.end()) { // att exists
                cnt += 1;
            }
        }
        if (cnt == key.size()) return false; // smaller key tuple exists
    }
    
    return true;
}

void combination(const vector<vector<string>>& relation, vector<int>& possibleKey, const int pickCount, int start) {
    if (possibleKey.size() >= pickCount) {
        if (isPossibleKey(relation, possibleKey)) {
            set<int> keyPool = vecToSet(possibleKey);
            if (canBeCandidateKey(keyPool)) {
                candidateKeys.push_back(keyPool);
            }
        }
    } else {
        int columnSize = relation.front().size();
        for(int i = start; i < columnSize; i++) {
            possibleKey.push_back(i);
            combination(relation, possibleKey, pickCount, i + 1);
            possibleKey.pop_back();
        }
    }
    
}

int solution(vector<vector<string>> relation) {
    int columnSize = relation.front().size();
    for(int i = 1; i <= columnSize; i++) {
        vector<int> possibleKey;
        combination(relation, possibleKey, i, 0);
    }
    
    int answer = candidateKeys.size();
    return answer;
}


int main(void) {
    int i = 1;
    int m = 5;
    cout << (1<<m) << endl;
    return 0;
}
