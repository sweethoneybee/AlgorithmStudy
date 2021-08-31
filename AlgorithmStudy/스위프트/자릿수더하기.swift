//
//  자릿수더하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/31.
//

import Foundation


func solution(_ n:Int) -> Int
{
    var answer:Int = 0
    var n = n
    while n > 0 {
        answer += n % 10
        n /= 10
    }
    
    return answer
}
