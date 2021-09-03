//
//  문자열내림차순으로배치하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/03.
//

import Foundation

func solution(_ s:String) -> String {
    return String(s.sorted { $0 > $1 })
}
