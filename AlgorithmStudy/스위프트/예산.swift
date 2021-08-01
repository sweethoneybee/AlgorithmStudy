//
//  예산.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/01.
//

import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var sum = 0
    var count = 0
    let request = d.sorted()
    for i in 0..<request.count {
        if sum + request[i] > budget {
            break
        }
        sum += request[i]
        count += 1
    }
    
    return count
}
