//
//  음양더하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/07/26.
//

import Foundation

func solution(_ absolutes:[Int], _ signs:[Bool]) -> Int {
    var sum = 0
    let len = absolutes.count
    for i in 0..<len {
        sum += absolutes[i] * (signs[i] ? 1 : -1)
    }
    
    return sum
}
