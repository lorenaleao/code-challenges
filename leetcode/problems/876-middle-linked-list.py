from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, data=0):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head : ListNode = None
    
    def addEnd(self, data):
        newNode = ListNode(data)
        
        # If the list is empty, 
        # set head to the new node
        if self.head == None:
            self.head = newNode
            return
        
        # If it's not, find the last node (it.next = None)
        #  and set it to the new node
        it = self.head
        while it.next != None:
            it =  it.next
        
        it.next = newNode
    
    def addBegin(self, data):
        newNode = ListNode(data)

        # If the list is empty,
        # set head to the new node
        if self.head == None:
            self.head = newNode
            return

        newNode.next = self.head
        self.head = newNode
    
    def addAfter(self, data, pos):
        it = self.head
        for _ in range(pos):
            if it == None:
                return
            if it.next == None: 
                break
            it = it.next
        
        newNode = ListNode(data)
        if it.next == None:
            it.next = newNode
            return
        
        newNode.next = it.next
        it.next = newNode
    
    def addListEnd(self, ls):
        for i in ls:
            self.addEnd(i)
    
    def print(self):
        it = self.head
        while it != None:
            print(f"{it.data} ->", end=" ")
            it = it.next
        print("None")



class Solution:
    def middleNodeRabbitTurtle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        rabbit = head
        turtle = head

        while rabbit.next != None and rabbit.next.next != None:
            turtle = turtle.next
            rabbit = rabbit.next.next
        
        if rabbit.next != None:
            return turtle.next
        return turtle
    
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        it = head
        count = 1
        while it.next != None:
            it = it.next
            count += 1
        
        count = count // 2
        
        it = head
        for i in range(count):
            it = it.next
        return it

s = Solution()
l = LinkedList()
l.addListEnd([1,2,3,4,5])
l.print()
print(f"middleNode: {s.middleNode(l.head).data}")
print(f"middleNodeRabbitTurtle: {s.middleNodeRabbitTurtle(l.head).data}")
l = LinkedList()
l.addListEnd([1,2,3,4,5,6])
l.print()
print(f"middleNode: {s.middleNode(l.head).data}")
print(f"middleNodeRabbitTurtle: {s.middleNodeRabbitTurtle(l.head).data}")