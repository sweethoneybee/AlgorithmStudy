//
//  27. Remove Element.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/09.
//

import Foundation

class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var removeCount = 0
        var length = nums.count
        
        for i in 0..<length {
            if i + removeCount >= length {
                break
            }
            
            if nums[i] == val {
                while i + removeCount < length {
                    removeCount += 1
                    if nums[length - removeCount] != val {
                        break
                    }
                }
                
                let changeIndex = length - removeCount
                let value = nums[i]
                nums[i] = nums[changeIndex]
                nums[changeIndex] = value
            }
        }
        
        return nums.count - removeCount
    }
    
    func bestSolution(_ nums: inout [Int], _ val: Int) -> Int {
        var begin = 0
        for i in 0..<nums.count {
            if nums[i] != val {
                nums[begin] = nums[i]
                begin += 1
            }
        }
        
        return begin
    }
}
