//
//  기능개발.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/27.
//

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int size = progresses.size();
    int dayMax = -1;
    int index = -1;
    for(int i = 0; i < size; i++)
    {
        int day = 0;
        while(1)
        {
            day++;
            progresses[i] += speeds[i];
            if(progresses[i] >= 100) break;
        }
        if(dayMax >= day)
        {
            answer[index]++;
        }
        else
        {
            answer.push_back(1);
            index++;
            dayMax = day;
        }
    }
    
    return answer;
}
