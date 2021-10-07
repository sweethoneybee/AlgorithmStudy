//
//  26. Remove Duplicates from Sorted Array.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/07.
//

import Foundation

class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var expectedNums: [Int] = []
        
        var previousNum = -101
        nums.forEach {
            if $0 != previousNum {
                expectedNums.append($0)
                previousNum = $0
            }
        }
        
        nums = expectedNums
        return nums.count
    }
}
