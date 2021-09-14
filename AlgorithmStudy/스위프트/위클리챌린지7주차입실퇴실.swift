//
//  위클리챌린지7주차입실퇴실.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/14.
//

import Foundation

struct EntranceTime {
    var enter: Int = 0
    var leave: Int = 0
}

func solution(_ enter:[Int], _ leave:[Int]) -> [Int] {
    var timeBoard: [EntranceTime] = .init(repeating: EntranceTime(), count: enter.count)
    for (index, item) in enter.enumerated() {
        timeBoard[item - 1].enter = index
    }
    for (index, item) in leave.enumerated() {
        timeBoard[item - 1].leave = index
    }
    
    var answer: [Int] = .init(repeating: 0, count: timeBoard.count)
    for i in 0..<enter.count {
        var leaveEarlier: Int?
        let before = enter[i] - 1
        for j in (i+1..<enter.count).reversed() {
            let later = enter[j] - 1
            if timeBoard[later].leave < timeBoard[before].leave {
                answer[before] += 1
                answer[later] += 1
                leaveEarlier = later
                continue
            }
            
            if let leaveEarlier = leaveEarlier,
               timeBoard[leaveEarlier].leave < timeBoard[later].leave {
                answer[before] += 1
                answer[later] += 1
            }
        }
    }
    
    return answer
}
