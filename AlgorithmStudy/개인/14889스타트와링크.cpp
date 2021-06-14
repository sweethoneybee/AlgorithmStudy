//
//  14889스타트와링크.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/14.
//

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int N = 0;
int result = 999999999;

void printing(const set<int>& team) {
    for(const auto p: team) {
        cout << p << " ";
    }
    cout << endl;
}

int sumStatOfTeam(const vector<vector<int>>& players, const set<int>& team) {
    int statOfTeam = 0;
    for (const auto& p: team) {
        for (int i = 0; i < N; ++i) {
            if (team.find(i) != team.end()) {
                statOfTeam += players[p][i];
            }
        }
    }
    return statOfTeam;
}

int calculate(const vector<vector<int>>& players, const vector<int>& team) {
    int margin = 0;
    
    set<int> teamA;
    for(const auto& p: team) teamA.insert(p);
    
    set<int> teamB;
    auto iterOfTeamA = team.begin();
    for(int i = 0; i < N; ++i) {
        if (iterOfTeamA != team.end() && (*iterOfTeamA) == i) {
            ++iterOfTeamA;
        } else {
            teamB.insert(i);
        }
    }
    
    int statOfTeamA = sumStatOfTeam(players, teamA);
    int statOfTeamB = sumStatOfTeam(players, teamB);
        
    margin = abs(statOfTeamA - statOfTeamB);
    return margin;
}

void pick(const vector<vector<int>>& players, vector<int>& team, const int start) {
    if (team.size() >= N / 2) {
        const int margin = calculate(players, team);
        result = min(result, margin);
    } else {
        for (int i = start; i < N; ++i) {
            team.push_back(i);
            pick(players, team, i + 1);
            team.pop_back();
        }
    }
}

int main(void) {
    cin >> N;
    vector<vector<int>> players(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> players[i][j];
        }
    }
    
    vector<int> team;
    pick(players, team, 0);
    cout << result;
    
    // 후욱후욱 종강만 해봐라
    // mvvm 혼내준다
    return 0;
}
