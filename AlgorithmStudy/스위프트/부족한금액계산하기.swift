//
//  부족한금액계산하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/03.
//

import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    let answer = Int64(money - (price + price * count) * count / 2)
    return answer < 0 ? answer : 0
}
