//
//  문자열내p와y의개수.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/04.
//

import Foundation

func solution(_ s:String) -> Bool
{
    var countP = 0
    var countY = 0
    
    for c in s {
        if c.lowercased() == "p" {
            countP += 1
            continue
        }
        
        if c.lowercased() == "y" {
            countY += 1
        }
    }

    guard countP != 0 || countY != 0 else {
        return true
    }
    
    if countP == countY {
        return true
    }
    
    return false
}
