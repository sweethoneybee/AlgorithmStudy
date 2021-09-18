//
//  멀쩡한사각형.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/18.
//

import Foundation

func solution(_ w:Int, _ h:Int) -> Int64{
    let w = Int64(w), h = Int64(h)
  
    return w * h - w - h + getGcd(w, h)
}

func getGcd(_ a: Int64, _ b: Int64) -> Int64 {
    return b == 0 ? a : getGcd(b, a % b)
}
