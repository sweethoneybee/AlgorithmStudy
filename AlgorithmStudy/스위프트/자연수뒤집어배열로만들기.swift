//
//  자연수뒤집어배열로만들기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/05.
//

import Foundation

func solution(_ n:Int64) -> [Int] {
    var target = n
    var answer = [Int]()
    while target > 0 {
        answer.append(Int(target % 10))
        target /= 10
    }
    return answer
}
