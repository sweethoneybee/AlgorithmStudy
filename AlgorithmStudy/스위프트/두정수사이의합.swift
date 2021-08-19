//
//  두정수사이의합.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/19.
//

import Foundation

func solution(_ a:Int, _ b:Int) -> Int64 {
    if a == b {
        return Int64(a)
    }
    
    return sumOperation(from: Int64(min(a, b)), to: Int64(max(a, b)))
}

func sumOperation(from start: Int64, to end: Int64) -> Int64 {
    return (end - start + 1) * (start + end) / 2
}
