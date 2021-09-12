//
//  약수의개수와덧셈.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/13.
//

import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var answer = 0
    for num in left...right {
        let count = divisorCount(num)
        answer = count % 2 == 0 ? (answer + num) : (answer - num)
    }
    return answer
}

func divisorCount(_ num: Int) -> Int {
    var count = 0
    for i in 1...num {
        if num % i == 0 {
            count += 1
        }
    }
    return count
}
