from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists2(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        it1 = list1
        it2 = list2

        prev1, prev2 = None, None
        while it1 != None or it2 != None:
            if it2 != None and it2.val <= it1.val:
                while it2 != None and it2.val <= it1.val:
                    prev2 = it2
                    it2 = it2.next
            
                prev2.next = it1
                it1 = it1.next
    
            
            if it1 != None and it1.val <= it2.val:
                while it1 != None and it1.val <= it2.val:
                    prev1 = it1
                    it1 = it1.next
            
                prev1.next = it2
                it2 = it2.next
    
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        it1 = list1
        it2 = list2

        prev1, prev2 = None, None
        while it1 != None or it2 != None:
            if it2.val <= it1.val:
                    prev2 = it2
                    it2 = it2.next
            
                prev2.next = it1
                it1 = it1.next
    
            
            if it1 != None and it1.val <= it2.val:
                while it1 != None and it1.val <= it2.val:
                    prev1 = it1
                    it1 = it1.next
            
                prev1.next = it2
                it2 = it2.next
        
            

                