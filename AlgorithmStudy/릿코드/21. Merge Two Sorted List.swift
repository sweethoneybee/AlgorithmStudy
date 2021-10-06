//
//  21. Merge Two Sorted List.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/10/06.
//

import Foundation

// Definition for singly-linked list.
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let dummyHead: ListNode? = ListNode()
        var tempHead = dummyHead
        var left = l1
        var right = l2
        
        while left != nil || right != nil {
            let leftValue = left != nil ? left!.val : 101
            let rightValue = right != nil ? right!.val : 101
            
            if leftValue < rightValue {
                tempHead?.next = ListNode(leftValue)
                left = left?.next
            } else {
                tempHead?.next = ListNode(rightValue)
                right = right?.next
            }
            tempHead = tempHead?.next
        }
        
        return dummyHead?.next
    }
}
