//
//  시저암호.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/31.
//

import Foundation


func solution(_ s:String, _ n:Int) -> String {
    let lowerAlpha = Array("abcdefghijklmnopqrstuvwxyz")
    let upperAlpha = Array("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    
    let answer = String(s.map { c in
        guard c != " " else { return c }
        return c.isLowercase ?
            lowerAlpha[(Int(c.asciiValue! - 97) + n) % 26]
            : upperAlpha[(Int(c.asciiValue! - 65) + n) % 26]
    })
    
    return answer
}
