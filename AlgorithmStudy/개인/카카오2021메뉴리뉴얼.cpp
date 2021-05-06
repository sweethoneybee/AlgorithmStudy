//
//  카카오2021메뉴리뉴얼.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/05/06.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> makeMenuPool(const vector<string>& orders) {
    vector<char> pool;
    vector<bool> mask(26, false);
    
    for(const auto& order: orders) {
        for(const auto& menu: order) {
            if (mask[menu - 'A'] == false) {
                mask[menu - 'A'] = true;
                pool.push_back(menu);
            }
        }
    }
    
    sort(pool.begin(), pool.end());
    return pool;
}

void combination(vector<string>& courseMenus, const vector<char>& menuPool, string& tempCourse, const int start, const int count) {
    if (tempCourse.length() >= count) {
        courseMenus.push_back(tempCourse);
    } else {
        int size = menuPool.size();
        for(int i = start; i < size; i++) {
            tempCourse.push_back(menuPool[i]);
            combination(courseMenus, menuPool, tempCourse, i + 1, count);
            tempCourse.pop_back();
        }
    }
}

int countAppeared(const vector<string>& orders, const string& courseMenu) {
    int count = 0;
    
    for(const auto& order: orders) {
        bool flag = true;
        for(const auto menu: courseMenu) {
            if (find(order.begin(), order.end(), menu) == order.end()) {
                flag = false;
                break;
            }
        }
        
        if (flag == true) count += 1;
    }
    
    return count;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<char> menuPool = makeMenuPool(orders);
    vector<string> courseMenus;
    for(const auto num: course) {
        string tempCourse = "";
        combination(courseMenus, menuPool, tempCourse, 0, num);
    }
    
    vector<vector<string>> newCourse(11);
    vector<int> courseBoard(11, 0);
    for(const auto& courseMenu: courseMenus) {
        int count = countAppeared(orders, courseMenu);
        int courseSize = courseMenu.length();
        if (count >= 2 && count >= courseBoard[courseSize]) {
            if (count > courseBoard[courseSize]) {
                newCourse[courseSize].clear();
                courseBoard[courseSize] = count;
            }
            newCourse[courseSize].push_back(courseMenu);
        }
    }
    
    
    vector<string> answer;
    for(const auto& v: newCourse) {
        for(const auto& s: v) {
            answer.push_back(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main(void) {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};
    
    solution(orders, course);
    return 0;
}
