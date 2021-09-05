//
//  3진법뒤집기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/05.
//

import Foundation

func solution(_ n:Int) -> Int {
    var n = n
    var digitStr = ""
    
    while n >= 3 {
        digitStr.append(String(n % 3))
        n = n / 3
    }
    digitStr.append(String(n))

    var ret = 0
    for (i, d) in digitStr.reversed().enumerated() {
        ret += pow(3, i) * d.wholeNumberValue!
    }
    
    return ret
}

func pow(_ target: Int, _ times: Int) -> Int {
    var ret = 1
    for _ in 0..<times {
        ret *= target
    }
    return ret
}

func bestSolutionFromProgrammers(_ n:Int) -> Int {
    let flipToThree = String(n,radix: 3)
    let answer = Int(String(flipToThree.reversed()),radix:3)!
    return answer
}
