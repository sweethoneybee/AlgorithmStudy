//
//  카카오2020문자열압축.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 100000;
    
    for(int compressLen = 1, length = s.length(); compressLen <= length; compressLen++) {
        int resultLen = 0;
        string compressFrame = s.substr(0, compressLen);
        int compressedCount = 1;
        
        for(int index = compressLen; index <= length;) {
            int leftStringLen = length - index;
            if (compressLen > leftStringLen) {
                resultLen += leftStringLen + compressLen + (compressedCount > 1 ? to_string(compressedCount).length() : 0);
                break;
            } else {
                string willCompress = s.substr(index, compressLen);
                if (compressFrame == willCompress) {
                    compressedCount += 1;
                } else {
                    resultLen += compressLen + (compressedCount > 1 ? to_string(compressedCount).length() : 0);
                    compressFrame = willCompress;
                    compressedCount = 1;
                }
                
                index += compressLen;
            }
        }

        if (resultLen < answer) {
            answer = resultLen;
        }
    }
    return answer;
}

int main(void) {
    string s = "xababcdcdababcdcd";
    cout << solution(s) << endl;
}
