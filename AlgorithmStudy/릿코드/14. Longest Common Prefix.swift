//
//  14. Longest Common Prefix.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/04.
//

import Foundation

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        var prefix = strs.first!
        
        strs.forEach { cmp in
            let len = min(prefix.count, cmp.count)
            var common = ""
            for i in 0..<len {
                if prefix[i] != cmp[i] {
                    break
                }
                common += String(prefix[i])
            }
            prefix = common
        }
        
        return prefix
    }
    
    func longestCommonPrefix2(_ strs: [String]) -> String {
        var prefix = strs.first!
        
        strs.forEach { cmp in
            prefix = prefix.commonPrefix(with: cmp)
        }
        
        return prefix
    }
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}
