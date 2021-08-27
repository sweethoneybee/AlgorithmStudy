//
//  이상한문자만들기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/27.
//

import Foundation

func solution(_ s:String) -> String {
    var result = ""
    var index = 0
    for c in s {
        if c == " " {
            result.append(c)
            index = 0
            continue
        }
        
        if index % 2 == 0 {
            result.append(c.uppercased())
            index += 1
            continue
        }
        
        result.append(c.lowercased())
        index += 1
    }
    
    return result
}
