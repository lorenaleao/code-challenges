from typing import List
import math

class MinHeap:
    def __init__(self) -> None:
        self.minheap = []

    def len(self) -> int:
        return len(self.minheap)
    
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

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        
        # Sort the meetings based on the start time.
        intervals.sort(key= lambda x: x[0])
        # One room will be needed at least if we heave at least one meeting,
        # so add the first meeting in the heap (rooms).
        rooms = MinHeap()
        rooms.push(intervals[0][1])
        # Initialize maxRooms with 1 because we will read at least one room as
        # said above.
        maxRooms = 1

        # Process the remaining meetings
        for i in range(1, len(intervals)):
            # Remove already finished meetings from the heap in comparison with
            # the current meeting.
            minEndMeeting = math.inf
            if rooms.len() > 0:
                minEndMeeting = rooms.peek()
            
            # If the current meeting start time is greater or equal the end
            # time of the ones that are in the heap, they ended. So, remove it.
            while intervals[i][0] >= minEndMeeting:
                rooms.pop()
                minEndMeeting = math.inf
                if rooms.len() > 0:
                    minEndMeeting = rooms.peek()

            # Here, rooms will be empty or the start time of the current
            # meeting is smaller than the first element in the heap, that is,
            # the meeting that will end first of all meetings in the heap. In
            # either case, we have to add the current meeting into the heap,
            # because we will need another room.
            rooms.push(intervals[i][1])

            # Update the maxRooms with the current number of rooms.
            if rooms.len() > maxRooms:
                maxRooms = rooms.len()
        
        return maxRooms