//
//  2016년.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/12.
//

import Foundation

func solution(_ a:Int, _ b:Int) -> String {
    let days = "SUN,MON,TUE,WED,THU,FRI,SAT".components(separatedBy: ",")
    var dayIndex = 4
    
    let dayOfMonth = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    var targetDays = b
    for i in 0..<a-1 {
        targetDays += dayOfMonth[i]
    }

    dayIndex = (dayIndex + targetDays) % 7
    return days[dayIndex]
}
