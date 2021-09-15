//
//  크레인인형뽑기게임.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/15.
//

import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    var answer = 0
    var pick: [Int] = []
    var board = board
    
    let height = board[0].count
    for move in moves {
        let move = move - 1
        
        for i in 0..<height {
            if board[i][move] != 0 {
                pick.append(board[i][move])
                board[i][move] = 0
                break
            }
        }
        
        if pick.count > 1,
           pick[pick.count - 1] == pick[pick.count - 2] {
            answer += 2
            pick.removeLast(2)
        }
    }
    
    return answer
}
