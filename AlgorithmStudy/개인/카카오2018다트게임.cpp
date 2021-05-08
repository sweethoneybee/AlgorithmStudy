//
//  카카오2018다트게임.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/08.
//

#include <string>
#include <vector>
using namespace std;

int multiTimes(const int value, const int times) {
    int ret = 1;
    for(int i = 0; i < times; i++) {
        ret *= value;
    }
    return ret;
}

int solution(string dartResult) {
    vector<int> scores;
    int index = 0;
    string s = "";
    int len = dartResult.length();
    for(int i = 0; i < len; i++) {
        const auto& c = dartResult[i];
        if (c >= '0' && c <= '9') {
            s.push_back(c);
        } else if (c == 'S' || c == 'D' || c == 'T') {
            int times = 0;
            switch (c) {
                case 'S':
                    times = 1;
                    break;
                case 'D':
                    times = 2;
                    break;
                case 'T':
                    times = 3;
                    break;
                default:
                    break;
            }
            int score = multiTimes(stoi(s), times);
            scores.push_back(score);
            s.clear();
            index += 1;
        } else {
            if (c == '*') {
                scores[index - 1] = scores[index - 1] * 2;
                if (index > 1) scores[index - 2] = scores[index - 2] * 2;
            } else if (c == '#') {
                scores[index - 1] = scores[index - 1] * -1;
            }
        }
    }
    
    int answer = 0;
    for(const auto score: scores) {
        answer += score;
    }
    return answer;
}
