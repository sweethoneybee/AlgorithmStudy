//
//  28. Implement strStr().cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/10.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }
        
        const int hayLength = haystack.length();
        const int needleLength = needle.length();
        
        for(int i = 0; i < hayLength; i++) {
            if(needle.front() == haystack[i]) {
                const int startIndex = i;
                int needleIndex = 0;
                while(needleIndex < needleLength && i < hayLength && haystack[i] == needle[needleIndex]) {
                    needleIndex += 1;
                    i += 1;
                }
                
                if(needleIndex == needleLength) {
                    return startIndex;
                }
                
                i = startIndex;
            }
        }
        
        return -1;
    }
};
