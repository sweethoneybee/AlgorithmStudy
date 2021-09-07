//
//  위클리챌린지6주차.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/06.
//

import Foundation

struct Boxer {
    var number: Int
    var weight: Int
    var winRate: Double
    var numberOfWinningOverHeavier: Int
}

func solution(_ weights:[Int], _ head2head:[String]) -> [Int] {
    var boxers = [Boxer]()
    zip(weights, head2head).forEach { weight, winInfo in
        var winCount = 0
        var numberOfWinningOverHeavier = 0
        var numberOfGames = 0
        
        for (index, info) in winInfo.enumerated() {
            guard info != "N" else {
                continue
            }
            
            if info == "W" {
                winCount += 1
                if weight < weights[index] {
                    numberOfWinningOverHeavier += 1
                }
            }
            numberOfGames += 1
        }
        
        let winRate = numberOfGames != 0 ? Double(winCount) / Double(numberOfGames) * 100 : 0.0
        
        boxers.append(Boxer(number: boxers.count + 1,
                            weight: weight,
                            winRate: winRate,
                            numberOfWinningOverHeavier: numberOfWinningOverHeavier))
    }
    
    return boxers
        .sorted {
            if $0.winRate != $1.winRate {
                return $0.winRate > $1.winRate
            } else if $0.numberOfWinningOverHeavier != $1.numberOfWinningOverHeavier {
                return $0.numberOfWinningOverHeavier > $1.numberOfWinningOverHeavier
            } else if $0.weight != $1.weight {
                return $0.weight > $1.weight
            }
            return $0.number < $1.number
        }
        .map { $0.number }
}
