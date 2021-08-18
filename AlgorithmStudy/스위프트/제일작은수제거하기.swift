//
//  제일작은수제거하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/18.
//

import Foundation

func solution(_ arr:[Int]) -> [Int] {
    if arr.count == 0 {
        return [-1]
    }
    
    var arr = arr
    arr.remove(at: findMinestNumberIndex(arr))
    return arr
}

func findMinestNumberIndex(_ arr: [Int]) -> Int{
    var index = 0
    var minNumber = 999999999
    for i in 0..<arr.count {
        if arr[i] < minNumber {
            minNumber = arr[i]
            index = i
        }
    }
    return index
}
