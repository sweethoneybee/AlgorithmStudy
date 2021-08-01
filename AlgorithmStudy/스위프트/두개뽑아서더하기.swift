//
//  두개뽑아서더하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/07/28.


import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var answer = Set<Int>()
    for i in 0..<numbers.count {
        pick(numbers, start: 0, count: 0, sum: 0, answer: &answer)
    }
    
    return answer.sorted()
}

func pick(_ numbers: [Int], start: Int, count: Int, sum: Int, answer: inout Set<Int>) {
    if count >= 2 {
        answer.insert(sum)
    } else {
        for i in start..<numbers.count {
            var sum = sum
            sum += numbers[i]
            pick(numbers, start: i + 1, count: count + 1, sum: sum, answer: &answer)
        }
    }
}
