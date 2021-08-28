//
//  최대공약수와최소공배수.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/28.
//

import Foundation

func solution(_ n:Int, _ m:Int) -> [Int] {
    return [greatestCommonFactor(n, m), leastCommonMultiple(n, m)]
}

func greatestCommonFactor(_ n: Int, _ m: Int) -> Int {
    var factor = min(n, m)
    while factor > 1
            && (n % factor != 0 || m % factor != 0 ) {
        factor -= 1
    }
    
    return factor
}

func leastCommonMultiple(_ n: Int, _ m: Int) -> Int {
    let multiple = max(n, m)
    var ret = multiple
    while ret % n != 0 || ret % m != 0 {
        ret += multiple
    }
    
    return ret
}
