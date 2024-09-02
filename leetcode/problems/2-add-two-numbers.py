from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def print(self):
        it = self
        while it != None:
            print(f"{it.val} ->", end=" ")
            it = it.next
        print("None")

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        rem = 0
        ans, curr = None, None
        while l1 != None and l2 != None:
            sumAux = l1.val + l2.val + rem
            sumDigit = sumAux % 10
            rem = sumAux // 10

            if ans == None:
                ans = ListNode(sumDigit)
                curr = ans
            else:
                curr.next = ListNode(sumDigit)

            if curr.next != None:
                curr = curr.next
            
            l1 = l1.next
            l2 = l2.next

        while l1 != None:
            sumAux = l1.val + rem
            sumDigit = sumAux % 10
            rem = sumAux // 10

            if ans == None:
                ans = ListNode(sumDigit)
                curr = ans
            else:
                curr.next = ListNode(sumDigit)

            if curr.next != None:
                curr = curr.next
            
            l1 = l1.next
        
        while l2 != None:
            sumAux = l2.val + rem
            sumDigit = sumAux % 10
            rem = sumAux // 10

            if ans == None:
                ans = ListNode(sumDigit)
                curr = ans
            else:
                curr.next = ListNode(sumDigit)

            if curr.next != None:
                curr = curr.next
            
            l2 = l2.next

        if rem != 0:
            curr.next = ListNode(rem)
        
        return ans
        
    

s = Solution()
ans = s.addTwoNumbers(ListNode(2, ListNode(4, ListNode(3, None))), ListNode(5, ListNode(6, ListNode(4, None)))) # [2,4,3] [5,6,4]
ans.print()

ans = s.addTwoNumbers(ListNode(0, None), ListNode(0, None)) # [0] [0]
ans.print()

# [9,9,9,9,9,9,9]
# [9,9,9,9]
ans = s.addTwoNumbers(
        ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, None))))))), 
        ListNode(9, ListNode(9, ListNode(9, ListNode(9, None)))),
    )
ans.print() # [8,9,9,9,0,0,0,1]

        