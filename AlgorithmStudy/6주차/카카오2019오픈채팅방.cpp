//
//  카카오2019오픈채팅방.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> splitWithWhitespace(const string& instruction) {
    vector<string> ret;
    string m = "";
    for(const auto& c: instruction) {
        if (c == ' ') {
            ret.push_back(m);
            m = "";
        } else {
            m.push_back(c);
        }
    }
    ret.push_back(m);
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> names;
    vector<pair<string, char>> orders; // <uid, 'E' or 'L'>
    for(const auto& r: record) {
        vector<string> instructions = splitWithWhitespace(r);
        const string doing = instructions.front();
        const string uid = instructions[1];
        const string nickname = instructions.size() == 3 ? instructions[2] : "";
        if (doing == "Enter") {
            names[uid] = nickname;
            orders.push_back(make_pair(uid, 'E'));
        } else if (doing == "Leave") {
            orders.push_back(make_pair(uid, 'L'));
        } else { // doing == "Change"
            names[uid] = nickname;
        }
    }
    
    const string enter = "님이 들어왔습니다.", leave = "님이 나갔습니다.";
    string nickname = "";
    for(const pair<string, char>& order: orders) {
        nickname = names[order.first];
        if (order.second == 'E') {
            answer.push_back(nickname + enter);
        } else { // order.second == 'L'
            answer.push_back(nickname + leave);
        }
    }
    
    return answer;
}


int main(void) {

    return 0;
}
