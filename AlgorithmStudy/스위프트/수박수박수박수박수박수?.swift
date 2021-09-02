//
//  수박수박수박수박수박수?.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/02.
//

import Foundation

func solution(_ n:Int) -> String {
    let s = ["수", "박"]
    var ret = ""
    
    for i in 0..<n {
        ret.append(s[i % 2])
    }
    
    return ret
}
