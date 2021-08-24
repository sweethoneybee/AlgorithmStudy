//
//  직사각형별찍기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/24.
//

import Foundation

func solution() {
    let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
    let (a, b) = (n[0], n[1])

    let row = String(repeating: "*", count: a)
    for _ in 0..<b {
        print(row)
    }

}
