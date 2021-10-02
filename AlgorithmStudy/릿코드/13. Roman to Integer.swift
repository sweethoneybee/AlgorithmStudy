//
//  13. Roman to Integer.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/03.
//

import Foundation

class Solution {
    func romanToInt(_ s: String) -> Int {
        let nums: [Int] = s.map {
            switch $0 {
            case "M": return 1000
            case "D": return 500
            case "C": return 100
            case "L": return 50
            case "X": return 10
            case "V": return 5
            case "I": return 1
            default: return 0
            }
        }
        
        var sum = 0
        for i in 0..<nums.count {
            if i >= nums.count - 1 {
                sum += nums[i]
                break
            }
            
            if nums[i] < nums[i + 1] {
                sum -= nums[i]
                continue
            }
            
            sum += nums[i]
        }
        
        return sum
    }
}
