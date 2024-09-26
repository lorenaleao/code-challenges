import math

class MinHeap:
    def __init__(self) -> None:
        self.minheap = []
    
    def parent(self, i) -> int:
        return self.minheap[math.floor((i-1)/2)]
    
    def pIdx(self, i) -> int:
        return math.floor((i-1)/2)
    
    def left(self, i) -> int:
        lIdx = self.lIdx(i)
        if lIdx >= len(self.minheap):
            return -1
        return self.minheap[2*i+1]
    
    def lIdx(self, i) -> int:
        return 2*i+1

    def right(self, i) -> int:
        rIdx = self.rIdx(i)
        if rIdx >= len(self.minheap):
            return -1
        return self.minheap[rIdx]
    
    def rIdx(self, i) -> int:
        return 2*i+2
    
    def push(self, n) -> None:
        self.minheap.append(n)
        i = len(self.minheap) - 1
        while i > 0 and self.parent(i) > self.minheap[i]:
            self.minheap[self.pIdx(i)], self.minheap[i] = self.minheap[i], self.parent(i)
            i = self.pIdx(i)
    
    def smallestChild(self, i) -> tuple:
        if self.right(i) == -1:
            if self.left(i) == -1:
                return (math.inf, math.inf)
            else:
                return self.lIdx(i), self.left(i)

        if self.left(i) <= self.right(i):
            return self.lIdx(i), self.left(i)
        else:
            return self.rIdx(i), self.right(i)
        

    def pop(self) -> int:
        minValue = self.peek()
        self.minheap[0] = self.minheap[-1]
        self.minheap.pop()
        i = 0
        smallestChild = self.smallestChild(i)
        while smallestChild[0] < len(self.minheap) and smallestChild[1] < self.minheap[i]:
            self.minheap[smallestChild[0]], self.minheap[i] = self.minheap[i], self.minheap[smallestChild[0]]
            i = smallestChild[0]
            smallestChild = self.smallestChild(i)
        return minValue
    
    def peek(self) -> int:
        return self.minheap[0]
    
    def print(self) -> None:
        print(self.minheap)

h = MinHeap()
print("inserting 2:")
h.push(2)
print("inserting 5:")
h.push(5)
print("inserting 9:")
h.push(9)
print("inserting 1:")
h.push(1)
print("inserting 18:")
h.push(18)
print("inserting 4:")
h.push(4)
print(h.peek())
h.print()
h.pop()
h.print()


