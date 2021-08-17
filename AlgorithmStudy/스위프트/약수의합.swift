//
//  약수의합.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/17.
//

import Foundation

func solution(_ n:Int) -> Int {
    var mod = 1
    var sum = 0
    while mod <= n {
        if n % mod == 0 {
            sum += mod
        }
        mod += 1
    }
    return sum
}
