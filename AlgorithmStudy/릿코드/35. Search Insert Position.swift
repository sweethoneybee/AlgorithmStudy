//
//  35. Search Insert Position.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/11.
//

class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        return binarySearch(nums, target: target, start: 0, end: nums.count - 1)
    }
    
    func binarySearch(_ nums: [Int], target: Int, start: Int, end: Int) -> Int {
        if start == end {
            if nums[start] < target {
                return start + 1
            }
            return start
        }
        
        let mid = (start + end) / 2
        if nums[mid] > target {
            return binarySearch(nums, target: target, start: start, end: end - 1)
        } else if nums[mid] < target {
            return binarySearch(nums, target: target, start: start + 1, end: end)
        } else {
            return mid
        }
    }
}
