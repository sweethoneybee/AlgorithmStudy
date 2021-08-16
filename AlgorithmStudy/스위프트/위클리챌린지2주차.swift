//
//  위클리챌린지2주차.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/08/16.
//

import Foundation

func solution(_ scores:[[Int]]) -> String {
    var answer = ""
    for i in 0..<scores.count {
        let evaluation = getEvaluationFrom(scores: scores, studentIndex: i)
        let avg = calculateAverage(scores: evaluation, studentNumber: i)
        answer.append(getGradeFor(average: avg))
    }
    return answer
}

func getEvaluationFrom(scores: [[Int]], studentIndex index: Int) -> [Int] {
    var evaluation = [Int]()
    for i in 0..<scores.count {
        evaluation.append(scores[i][index])
    }
    return evaluation
}

func calculateAverage(scores: [Int], studentNumber me: Int) -> Double {
    let myScore = scores[me]
    var maxScore = -1
    var minScore = 1000
    var sum = 0
    
    for i in 0..<scores.count {
        if i == me {
            continue
        }
        
        let s = scores[i]
        minScore = min(minScore, s)
        maxScore = max(maxScore, s)
        sum += s
    }
    
    if minScore <= myScore && maxScore >= myScore {
        sum += myScore
        return Double(sum) / Double((scores.count))
    }
    return Double(sum) / Double((scores.count - 1))
}

func getGradeFor(average score: Double) -> String {
    switch score {
    case 90...100:  return "A"
    case 80..<90:   return "B"
    case 70..<80:   return "C"
    case 50..<70:   return "D"
    default:        return "F"
    }
}
