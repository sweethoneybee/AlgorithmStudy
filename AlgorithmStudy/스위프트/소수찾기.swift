//
//  소수찾기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/11.
//

import Foundation

func solution(_ n:Int) -> Int {
    var chae = Array(repeating: true, count: n + 1)
    
    var answer = 0
    for i in 2..<chae.count {
        if chae[i] == false {
            continue
        }
        
        answer += 1
        var mul = 2
        var num = i * mul
        while num < chae.count {
            chae[num] = false
            mul += 1
            num = i * mul
        }
    }

    return answer
}

