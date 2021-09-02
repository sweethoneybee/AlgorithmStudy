//
//  문자열을정수로바꾸기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/02.
//

import Foundation

func solution(_ s:String) -> Int {
    
    if s.hasSuffix("-"),
       let range = s.range(of: "-") {
        let absStr = s[range.lowerBound...]
        
        return Int(absStr)! * -1
    }
    
    return Int(s)!
}
