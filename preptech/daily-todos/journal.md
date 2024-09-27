# 8 de setembro de 2024

- [x] ler editorial https://leetcode.com/problems/ransom-note/editorial/?envType=study-plan-v2&envId=top-interview-150
- [x] ler editorial https://leetcode.com/problems/isomorphic-strings/editorial/?envType=study-plan-v2&envId=top-interview-150
- [x] ler padrões: https://blog.algomaster.io/p/15-leetcode-patterns
    - lido até 6. Monotonic Stack
- [x] Monotonic Stack Data Structure Explained: https://www.youtube.com/watch?v=Dq_ObZwTY_Q 
- [x] fazer https://leetcode.com/problems/next-greater-element-i/description/

# 9 de setembro de 2024

- [x] ler editorial https://leetcode.com/problems/next-greater-element-i/description/
- [ ] ler editorial https://leetcode.com/problems/daily-temperatures/editorial/
- [ ] ler editorial https://leetcode.com/problems/swap-nodes-in-pairs/description/
- [ ] ler editorial https://leetcode.com/problems/majority-element/description/

- [ ] continue https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150

12 sep
https://leetcode.com/problems/first-missing-positive/editorial/
fazer problemas de ciclo
fazer resto problemas de linked list

# 22 de setembro de 2024

- [x] https://algo.monster/problems/binary-search-monotonic fiz todos os até o newspapers
- [x] https://leetcode.com/studyplan/binary-search/ 7 done hoje :D total = 8/42

# 23 de setembro de 2024

- [x] https://algo.monster/problems/newspapers_split
- [x] https://algo.monster/problems/binary-search-speedrun fiz 3 speedruns, 4o fiquei empacada
- [x] https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
- [x] https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

# 24 de setembro de 2024 

- [x] Continuar speedrun: https://algo.monster/problems/binary-search-speedrun
    - [x] tentei 4, li editorial https://leetcode.com/problems/single-element-in-a-sorted-array/
    - [x] tentei 5, li solução algomonster
- [x] Aula 10 PrepTech: Heaps and Priority Queue
- [x] Comecei a fazer e pensar na solução de https://leetcode.com/problems/meeting-rooms-ii/

# 27 de setembro de 2024

- [x] Implementar solução que pensei: https://leetcode.com/problems/meeting-rooms-ii/

# TODO
- [ ] rodar exemplos na mão: https://leetcode.com/problems/single-element-in-a-sorted-array/
- [ ] ler editorial https://leetcode.com/problems/my-calendar-i/
- [ ] Continuar speedrun (6, 7, 8) https://algo.monster/problems/binary-search-speedrun

- [ ] https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/
- [ ] https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1337729413/?envType=study-plan-v2&envId=binary-search
- [ ] https://www.cs.cornell.edu/courses/cs211/2006sp/Lectures/L06-Induction/binary_search.html
- [ ] https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
- [ ] https://leetcode.com/problems/divide-chocolate/description/?envType=study-plan-v2&envId=binary-search

ler
```python
def __init__(self):
        self.s = []
        self.min_s = []
    def push(self, val: int) -> None:
        self.s.append(val)
        if not self.min_s or val <= self.min_s[-1]:
            self.min_s.append(val)
    def pop(self) -> None:
        popped = self.s.pop()
        if popped == self.min_s[-1]:
            self.min_s.pop()
    def top(self) -> int:
        return self.s[-1]
    def getMin(self) -> int:
        return self.min_s[-1]
```

- [ ] WIP https://leetcode.com/problems/meeting-rooms-ii/