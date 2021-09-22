//
//  7. Reverse Integer.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/22.
//

import Foundation

class Solution {
    func reverse(_ x: Int) -> Int {
        var absValue = 1
        for _ in 0..<31 {
            absValue *= 2
        }
    
        var reversedX = String(String(x).reversed())
        if let newX = Int(reversedX) {
            if newX <= absValue - 1 {
                return newX
            }
            return 0
        }
        
        reversedX.removeLast()
        if let newXAbs = Int(reversedX) {
            let newX = -1 * newXAbs
            if newX >= -1 * absValue {
                return newX
            }
            return 0
        }
        
        return 0
    }
    
    // https://leetcode.com/problems/reverse-integer/discuss/239996/Swift-12ms
    func bestSoultion(_ x: Int) -> Int {
        var unsignedX = abs(x)
        var reverse = 0
        while unsignedX > 0 {
            let lastDigit = unsignedX % 10
            reverse = reverse * 10 + lastDigit
            unsignedX /= 10
            
            if reverse > Int32.max {
                return 0
            }
        }
        if x < 0 {
            return -reverse
        }
        return 0
    }
}
