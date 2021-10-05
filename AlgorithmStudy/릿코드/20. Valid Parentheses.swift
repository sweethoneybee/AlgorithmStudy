//
//  20. Valid Parentheses.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/05.
//

import Foundation

class Solution {
    func isValid(_ s: String) -> Bool {
        var stack: [Character] = []
        var answer = true
        let kkanbu: [Character: Character] = [
            ")": "(",
            "]": "[",
            "}": "{"
        ]

        s.forEach { p in
            if p == "(" || p == "[" || p == "{" {
                stack.append(p)
            } else if kkanbu[p] != stack.popLast() {
                answer = false
            }
        }
        
        return stack.isEmpty && answer
    }
}
