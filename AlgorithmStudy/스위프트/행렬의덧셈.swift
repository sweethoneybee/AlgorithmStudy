//
//  행렬의덧셈.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/24.
//

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var retArr = [[Int]]()
    for i in 0..<arr1.count {
        retArr.append([])
        for j in 0..<arr1[i].count {
            retArr[i].append(arr1[i][j] + arr2[i][j])
        }
    }
    
    return retArr
}
