//
//  체육복.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/10.
//

import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var students = Array(repeating: 1, count: n)
    for i in lost {
        students[i - 1] -= 1
    }
    for i in reserve {
        students[i - 1] += 1
    }
    
    if students[0] == 0, students[1] == 2 {
        students[0] += 1
        students[1] -= 1
    }
    
    for i in 1..<n-1 {
        guard students[i] != 0 else { continue }
        
        if students[i - 1] >= 2 {
            students[i - 1] -= 1
            students[i] += 1
            continue
        }
        
        if students[i + 1] >= 2 {
            students[i + 1] -= 1
            students[i] += 1
        }
    }
    
    if students[n - 1] == 0, students[n - 2] == 2 {
        students[n - 1] += 1
        students[n - 2] -= 1
    }
    
    var answer = 0
    for s in students {
        if s > 0 {
            answer += 1
        }
    }
    return answer
}
