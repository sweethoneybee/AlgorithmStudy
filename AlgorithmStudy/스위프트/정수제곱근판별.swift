//
//  정수제곱근판별.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/29.
//

import Foundation


func solution2(_ n:Int64) -> Int64 {
    let num = Double(n)
    let s = sqrt(num)
        
    if s.rounded() == s {
        return Int64(pow(s + 1, 2))
    }
    return -1
}
