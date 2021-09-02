//
//  숫자문자열과영단어.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/02.
//

import Foundation

func solution(_ s:String) -> Int {
    var nums = ""

    var i = 0
    while i < s.count {
        let c = s[i]
        if Int(c) != nil {
            nums.append(c)
            i += 1
            continue
        }
        
        switch c {
        case "z": // zero
            nums.append("0")
            i += 3
        case "o": // one
            nums.append("1")
            i += 2
        case "t": // two, three
            let nextC = s[i + 1]
            if nextC == "w" {
                nums.append("2")
                i += 2
                break
            }
            if nextC == "h" {
                nums.append("3")
                i += 4
            }
        case "f": // four, five
            let nextC = s[i + 1]
            if nextC == "o" {
                nums.append("4")
                i += 3
                break
            }
            if nextC == "i" {
                nums.append("5")
                i += 3
            }
        case "s": // six, seven
            let nextC = s[i + 1]
            if nextC == "i" {
                nums.append("6")
                i += 2
                break
            }
            if nextC == "e" {
                nums.append("7")
                i += 4
            }
        case "e": // eight
            nums.append("8")
            i += 4
        case "n": // nine
            nums.append("9")
            i += 3
        default:
            fatalError()
        }
        
        i += 1
    }
    
    return Int(nums) ?? 0
}


extension String {
    subscript(index: Int) -> String {
        return String(self[self.index(self.startIndex, offsetBy: index)])
    }
}
