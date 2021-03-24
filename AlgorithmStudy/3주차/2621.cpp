//
//  2621.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isStraight(const vector<pair<int, int>>& cardCountAndNumber) {
    if (cardCountAndNumber.size() < 5) {
        return false;
    }
    
    for(int i = 0, size = cardCountAndNumber.size(); i < size - 1; i++) {
        if(cardCountAndNumber[i].second - 1 != cardCountAndNumber[i+1].second) {
            return false;
        }
    }
    return true;
}

int main(void) {
    vector<pair<char, int>> cards;
    vector<int> counting(10, 0);
    
    char color;
    int num;
    cin >> color >> num;
    cards.push_back(make_pair(color, num));
    counting[num] += 1;
    
    bool isAllSameColor = true;
    int maxNum = num;
    for(int i = 0; i < 4; i++) {
        cin >> color >> num;
        if (isAllSameColor && color != cards.back().first) {
            isAllSameColor = false;
        }
        if (num > maxNum) {
            maxNum = num;
        }
        
        cards.push_back(make_pair(color, num));
        counting[num] += 1;
    }

    vector<pair<int, int>> cardCountAndNumber;
    for(int numeber = 0, size = counting.size(); numeber < size; numeber++) {
        if (counting[numeber] > 0) {
            cardCountAndNumber.push_back(make_pair(counting[numeber], numeber));
        }
    }
    sort(cardCountAndNumber.begin(), cardCountAndNumber.end(), [](pair<int, int> a, pair<int, int> b)->bool{
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    });
    
    int score = 0;
    
    if (isAllSameColor && isStraight(cardCountAndNumber)) {
        score = 900 + maxNum;
    } else if (cardCountAndNumber.front().first == 4) {
        score = 800 + cardCountAndNumber.front().second;
    } else if (cardCountAndNumber.front().first == 3 && cardCountAndNumber[1].first == 2) {
        score = cardCountAndNumber.front().second * 10 + cardCountAndNumber[1].second + 700;
    } else if (isAllSameColor) {
        score = maxNum + 600;
    } else if (isStraight(cardCountAndNumber)) {
        score = maxNum + 500;
    } else if (cardCountAndNumber.front().first == 3) {
        score = cardCountAndNumber.front().second + 400;
    } else if (cardCountAndNumber.front().first == 2 && cardCountAndNumber[1].first == 2) {
        int bigger, smaller;
        if (cardCountAndNumber.front().second > cardCountAndNumber[1].second) {
            bigger = cardCountAndNumber.front().second;
            smaller = cardCountAndNumber[1].second;
        } else {
            bigger = cardCountAndNumber[1].second;
            smaller = cardCountAndNumber.front().second;
        }
        score = bigger * 10 + smaller + 300;
    } else if (cardCountAndNumber.front().first == 2) {
        score = cardCountAndNumber.front().second + 200;
    } else {
        score = maxNum + 100;
    }
    cout << score;
    return 0;
}
