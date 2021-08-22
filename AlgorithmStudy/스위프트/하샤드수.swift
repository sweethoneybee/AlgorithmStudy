//
//  하샤드수.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/22.
//

import Foundation

func solution(_ x:Int) -> Bool {
    let divider = digitSumFor(number: x)
    
    return isHashard(number: x, with: divider)
}

func isHashard(number num: Int, with divider: Int) -> Bool {
    return num % divider == 0
}

func digitSumFor(number num: Int) -> Int {
    var num = num
    var sum = 0
    while num > 0 {
        sum += num % 10
        num /= 10
    }
    
    return sum
}
