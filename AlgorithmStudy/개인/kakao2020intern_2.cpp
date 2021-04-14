#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long operateExpression(vector<long long> nums, vector<pair<char, int>> opers, const vector<char> operOrders) {
    for(const auto inTurnOper: operOrders) {
        for(int i = 0; i < opers.size(); i++) {
            if (opers[i].first == inTurnOper) {
                long long result = 0;
                switch (inTurnOper) {
                    case '*':
                        result = nums[i] * nums[i + 1];
                        break;
                    case '+':
                        result = nums[i] + nums[i + 1];
                        break;
                    case '-':
                        result = nums[i] - nums[i + 1];
                        break;
                    default:
                        break;
                }
                nums.erase(nums.begin() + i);
                nums[i] = result;
                opers.erase(opers.begin() + i);
                i -= 1;
            }
        }
    }

    return nums.front();
}
long long solution(string expression) {
    long long answer = 0;
    
    vector<pair<char, int>> opers;
    for(int i = 0, len = expression.length(); i < len; i++) {
        if (expression[i] < '0' || expression[i] > '9') {
            opers.push_back(make_pair(expression[i], i));
        }
    }
    
    
    vector<long long> nums;
    nums.push_back(stoll(expression.substr(0, opers.front().second)));
    for(int i = 0, size = opers.size(); i < size - 1; i++) {
        int start = opers[i].second + 1;
        int end = opers[i + 1].second;
        nums.push_back(stoll(expression.substr(start, end - start)));
    }
    nums.push_back(stoll(expression.substr(opers.back().second + 1)));
    
    vector<char> operOrders = {'*', '+', '-'};
    do {
        long long result = abs(operateExpression(nums, opers, operOrders));
        if (answer < result) {
            answer = result;
        }
    } while (next_permutation(operOrders.begin(), operOrders.end()));
    return answer;
}


int main(void) {
    string expression = "100-200*300-500+20";
    cout << solution(expression) << endl;
    
    return 0;
}
