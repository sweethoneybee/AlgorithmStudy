//
//  카카오2021순위검색.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/06.
//
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string, vector<int>> pool;

void makePool(const vector<string>& submit, string key, const int start) {
    if (start >= submit.size() - 1) {
        int score = stoi(submit.back());
        pool[key].push_back(score);
    } else {
        makePool(submit, key + submit[start], start + 1);
        makePool(submit, key + "-", start + 1);
    }
}

int lowerBound(const vector<int>& scores, const int value) {
    int low = 0, mid = 0, high = scores.size();
    while(low < high) {
        mid = (low + high) / 2;
        if (value <= scores[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

vector<int> solution(vector<string> info, vector<string> query) {
    
    for(const auto& one: info) {
        vector<string> submit(5);
        stringstream ss(one);
        ss >> submit[0] >> submit[1] >> submit[2] >> submit[3] >> submit[4];
        makePool(submit, "", 0);
    }

    for(auto& v: pool) {
        sort(v.second.begin(), v.second.end());
    }
    
    vector<int> answer;
    for(const auto& one: query) {
        vector<string> str(4);
        string temp, score;
        stringstream ss(one);
        ss >> str[0] >> temp >> str[1] >> temp >> str[2] >> temp >> str[3] >> score;
        string q = "";
        for(const auto& s: str) q += s;
        const auto result = pool.find(q);
        int count = 0;
        if (result != pool.end()) {
            const auto scores = result->second;
            int low = lowerBound(scores, stoi(score));
            count = scores.size() - low;
        }
        answer.push_back(count);
    }
    
    return answer;
}

int main(void) {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    
    solution(info, query);
    return 0;
}
