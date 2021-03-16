//
//  1063.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/03/17.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Commands {
    R = 'R',
    L = 'L',
    T = 'T',
    B = 'B'
};

bool check(const pair<int, int>& coord);
void makeMove(pair<int, int>& coord, const char& command);
pair<int, int> getMovedCoord(const pair<int, int>& coord, const string& command);

bool check(const pair<int, int>& coord) {
    const int x = coord.first;
    const int y = coord.second;
    
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return false;
    }
    else {
        return true;
    }
}

void makeMove(pair<int, int>& coord, const char& command) {
    switch (command) {
        case Commands::R:
            coord.first += 1;
            break;
        case Commands::L:
            coord.first -= 1;
            break;
        case Commands::T:
            coord.second += 1;
            break;
        case Commands::B:
            coord.second -= 1;
            break;
    }
}

pair<int, int> getMovedCoord(const pair<int, int>& coord, const string& command) {
    pair<int, int> willMoveTo = coord;
    makeMove(willMoveTo, command[0]);
    
    if (command.length() >= 2) {
        makeMove(willMoveTo, command[1]);
    }
    
    return willMoveTo;
}

int main(void) {
    string kingInput, stoneInput = "";
    int N = 0;
    
    cin >> kingInput >> stoneInput >> N;
    
    vector<string> commands;
    for (int i = 0; i < N; i++) {
        string input = "";
        cin >> input;
        commands.push_back(input);
    }
    
    pair<int, int> kingCoord = make_pair(kingInput[0] - 'A', kingInput[1] - '1');
    pair<int, int> stoneCoord = make_pair(stoneInput[0] - 'A', stoneInput[1] - '1');

    for (const auto& command: commands) {
        const pair<int, int> kingWillMoveTo = getMovedCoord(kingCoord, command);
        
        if (kingWillMoveTo == stoneCoord) {
            const pair<int, int> stoneWillMoveTo = getMovedCoord(stoneCoord, command);
            
            if (check(stoneWillMoveTo)) {
                kingCoord = kingWillMoveTo;
                stoneCoord = stoneWillMoveTo;
            }
        } else {
            if (check(kingWillMoveTo)) {
                kingCoord = kingWillMoveTo;
            }
        }
    }
    
    cout << char(kingCoord.first + 'A') << char(kingCoord.second + '1') << endl;
    cout << char(stoneCoord.first + 'A') << char(stoneCoord.second + '1') << endl;
    
    return 0;
}
