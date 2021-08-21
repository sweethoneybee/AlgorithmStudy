//
//  가운데글자가져오기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/21.
//

import Foundation

func solution(_ s:String) -> String {
    let mid = s.count / 2
    
    if s.count % 2 != 0 {
        return String(s[s.index(s.startIndex, offsetBy: mid)])
    }
    
    return String(s[s.index(s.startIndex, offsetBy: mid - 1)])
        + String(s[s.index(s.startIndex, offsetBy: mid)])
}
