from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def swapPair(self, prev: Optional[ListNode], curr: Optional[ListNode]):
        aft = curr.next
        curr.next = aft.next
        aft.next = curr
        if prev != None:
            prev.next = aft
        

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        curr = head
        second = head
        if head.next != None:
            second = head.next
        
        prev = None
        while curr != None and curr.next != None:
            self.swapPair(prev, curr)
            if curr == head:
                head = curr.next
            prev = curr
            curr = curr.next
        
        return second