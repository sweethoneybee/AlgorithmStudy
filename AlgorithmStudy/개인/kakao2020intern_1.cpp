//
//  kakao2020intern_1.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/14.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int distance(const pair<int, int> from, const pair<int, int> to) {
    return abs(from.first - to.first) + abs(from.second - to.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    const string L = "L";
    const string R = "R";
    
    vector<pair<int, int>> numberCoord;
    numberCoord.push_back(make_pair(3, 1)); // 0
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            numberCoord.push_back(make_pair(i, j));
        }
    }
    
    pair<int, int> leftFinger = make_pair(3, 0);
    pair<int, int> rightFinger = make_pair(3, 2);
    for(const auto num: numbers) {
        if (num == 1 || num == 4 || num == 7) {
            leftFinger = numberCoord[num];
            answer.append(L);
        } else if (num == 3 || num == 6 || num == 9) {
            rightFinger = numberCoord[num];
            answer.append(R);
        } else {
            pair<int, int> target = numberCoord[num];
            int leftDistance = distance(leftFinger, target);
            int rightDistance = distance(rightFinger, target);
            
            if (leftDistance < rightDistance) {
                leftFinger = numberCoord[num];
                answer.append(L);
            } else if (leftDistance > rightDistance) {
                rightFinger = numberCoord[num];
                answer.append(R);
            } else if (hand == "left") { // leftDistance == rightDistance
                leftFinger = numberCoord[num];
                answer.append(L);
            } else {
                rightFinger = numberCoord[num];
                answer.append(R);
            }
        }
    }
    
    return answer;
}

int main(void) {
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    
    string result = solution(numbers, hand);
    cout << result << endl;
    return 0;
}


