//
//  9. Palindrome Number.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/23.
//

import Foundation

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        let originalX = String(x)
        let reversedX = String(originalX.reversed())
        
        for i in 0..<originalX.count / 2 + 1 {
            if originalX[i] != reversedX[i] {
                return false
            }
        }
        
        return true
    }
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}
