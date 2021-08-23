//
//  콜라츠추측.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/23.
//

import Foundation

func solution(_ num:Int) -> Int {
    var num = num
    var count = 0
    while num != 1, count < 500 {
        count += 1
        if num % 2 == 0 {
            num /= 2
        } else {
            num = num * 3 + 1
        }
    }
    
    return num == 1 ? count : -1
}
