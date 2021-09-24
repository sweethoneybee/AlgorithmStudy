//
//  2. Add Two Numbers.swift
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/09/24.
//

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var leftNode = l1
        var rightNode = l2
        var hasPlacePlus = false
        
        var digitSum = l1!.val + l2!.val
        if digitSum >= 10 {
            hasPlacePlus = true
            digitSum %= 10
        } else {
            hasPlacePlus = false
        }
        
        let head = ListNode(digitSum)
        var tempNode: ListNode? = head
        leftNode = leftNode?.next
        rightNode = rightNode?.next
        
        while leftNode != nil || rightNode != nil || hasPlacePlus {
            var leftValue = 0, rightValue = 0
            if leftNode != nil {
                leftValue = leftNode!.val
            }
            if rightNode != nil {
                rightValue = rightNode!.val
            }
            
            digitSum = leftValue + rightValue + (hasPlacePlus ? 1 : 0)
            if digitSum >= 10 {
                hasPlacePlus = true
                digitSum %= 10
            } else {
                hasPlacePlus = false
            }
            
            tempNode?.next = ListNode(digitSum)
            
            tempNode = tempNode?.next
            leftNode = leftNode?.next
            rightNode = rightNode?.next
        }
        
        return head
    }
    
    func 풀이본후개선버전(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var leftNode = l1
        var rightNode = l2
        var carry = 0
        
        let dummyHead = ListNode(0)
        var tempNode: ListNode? = dummyHead
        
        while leftNode != nil || rightNode != nil {
            let leftValue = leftNode == nil ? 0 : leftNode!.val
            let rightValue = rightNode == nil ? 0 : rightNode!.val
            let digitSum = leftValue + rightValue + carry
            
            carry = digitSum / 10
            tempNode?.next = ListNode(digitSum % 10)
            
            tempNode = tempNode?.next
            if leftNode != nil {
                leftNode = leftNode?.next
            }
            if rightNode != nil {
                rightNode = rightNode?.next
            }
        }
        
        if carry > 0 {
            tempNode?.next = ListNode(carry)
        }
        return dummyHead.next
    }
}
