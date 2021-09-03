//
//  문자열내마음대로정렬하기.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/03.
//

import Foundation

func solution(_ strings:[String], _ n:Int) -> [String] {
    return strings.sorted {
        guard $0[n] != $1[n] else {
            return $0 < $1
        }
        
        return $0[n] < $1[n]
    }
}

extension String {
    subscript(index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}
