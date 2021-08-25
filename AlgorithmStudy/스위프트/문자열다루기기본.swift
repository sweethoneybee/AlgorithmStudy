//
//  문자열다루기기본.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/25.
//

import Foundation

func solution(_ s:String) -> Bool {
    guard s.count == 4 || s.count == 6 else { return false }
    
    for c in s {
        if c.isNumber == false {
            return false
        }
    }
    return true
}
