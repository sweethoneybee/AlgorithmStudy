//
//  가장큰수.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/19.
//

import Foundation

func solution(_ numbers:[Int]) -> String {
    let answer = numbers
        .map { String($0) }
        .sorted {
            let lhs = $0 + $1
            let rhs = $1 + $0
            
            return lhs > rhs
        }
        .reduce("") { $0 + $1 }
    
    return Int(answer) != 0 ? answer: "0"
}
