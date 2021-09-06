//
//  위클리챌린지4주차.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/06.
//

import Foundation

func solution(_ table:[String], _ languages:[String], _ preference:[Int]) -> String {
    var domainScores = [String: Int]()
    for row in table {
        let languageRanks = row.components(separatedBy: " ")

        var totalScore = 0
        var score = 5
        languageRanks[1...].forEach { rank in
            if let index = languages.firstIndex(of: rank) {
                totalScore += preference[index] * score
            }
            score -= 1
        }
        
        domainScores[languageRanks[0]] = totalScore
    }
    
    return domainScores.sorted {
        return $0.value != $1.value ? $0.value > $1.value : $0.key < $1.key
    }.first!.key
}
