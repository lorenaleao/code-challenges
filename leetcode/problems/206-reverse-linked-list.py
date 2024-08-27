# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        it = head
        prev = None
        aft = None
        while it != None:
            aft = it.next
            it.next = prev
            prev = it
            it = aft

        head = prev
        return head


"""
        1 -> 2 -> 3 -> None
        it
    p
    a

None <- 1 -> 2 -> 3 -> None
             a  
        p
             it

None <- 1 <- 2 -> 3 -> None
                  a  
             p
                  it

None <- 1 <- 2 <- 3 
                        a  
                  p
                        it

"""
