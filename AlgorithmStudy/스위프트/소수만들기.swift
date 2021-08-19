//
//  소수만들기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/10.
//

import Foundation

func solution(_ nums:[Int]) -> Int {
    var answer = 0
    
    pickNum(nums: nums, target: 0, start: 0, count: 0, answer: &answer)
    return answer
}

func pickNum(nums: [Int], target: Int, start: Int, count: Int, answer: inout Int) {
    if count >= 3 {
        if isPrimeNumber(for: target) {
            answer += 1
        }
        return
    }
    
    for i in start..<nums.count {
        pickNum(nums: nums, target: target + nums[i], start: i + 1, count: count + 1, answer: &answer)
    }
}

func isPrimeNumber(for num: Int) -> Bool {
    for i in 2..<num {
        if num % i == 0 {
            return false
        }
    }
    return true
}
