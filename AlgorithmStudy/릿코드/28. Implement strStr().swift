//
//  28. Implement strStr().swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/10.
//

import Foundation

class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        if needle.isEmpty {
            return 0
        }
        
        let hayLength = haystack.count
        let needleLength = needle.count
        var i = 0
        
        while i < hayLength {
            if needle.first! == haystack[i] {
                let startIndex = i
                var needleIndex = 0
                while needleIndex < needleLength,
                      i < hayLength,
                      haystack[i] == needle[needleIndex] {
                    needleIndex += 1
                    i += 1
                }
                
                if needleIndex == needleLength {
                    return startIndex
                }
                
                i = startIndex
            }
            i += 1
        }
        
        return -1
    }
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}
