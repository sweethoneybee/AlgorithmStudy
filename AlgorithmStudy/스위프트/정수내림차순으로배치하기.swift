//
//  정수내림차순으로배치하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/30.
//

import Foundation

func solution(_ n:Int64) -> Int64 {
    var arr = [Int64]()
    var n = n
    while n >= 10 {
        arr.append(n % 10)
        n = n / 10
    }
    arr.append(n % 10)
    arr.sort()
    var result: Int64 = 0
    
    var digit: Int64 = 1
    for num in arr {
        result += num * digit
        digit *= 10
    }
    return result
}

// 이상하다 분명 String(n) 후 Array 변환 안되었었는데...
func solution2(_ n:Int64) -> Int64 {
    return Int64(String(Array(String(n)).sorted(by: >)))!
}

