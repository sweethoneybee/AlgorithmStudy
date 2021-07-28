//
//  로또의최고순위와최저순위.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/07/26.
//

import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var zero = 0
    var hit = 0
    for num in lottos {
        if num == 0 {
            zero += 1
            continue
        }
        
        if win_nums.firstIndex(of: num) != nil {
            hit += 1
        }
    }
    
    var rank = 7 - hit - zero
    if rank >= 6 {
        rank = 6
        return [rank, rank]
    } else {
        return [rank, rank + zero <= 6 ? rank + zero : 6]
    }
}
