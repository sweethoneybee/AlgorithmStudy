//
//  나누어떨어지는숫자배열.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/21.
//

import Foundation

func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    let result = arr.filter { $0 % divisor == 0 }
    return result.count != 0 ? result.sorted() : [-1]
}
