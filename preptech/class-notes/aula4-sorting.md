# Aula 4: Sorting

- Count Sort: https://replit.com/join/aksbxqncjo-edcaraujo1
- https://leetcode.com/problems/find-the-duplicate-number/submissions/1364895196

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        slow = nums[0]
        fast = nums[0]
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        
        return slow
```
- https://www.geeksforgeeks.org/defaultdict-in-python/

## Problemas

- [ ] https://leetcode.com/problems/squares-of-a-sorted-array/
- [ ] https://leetcode.com/problems/valid-anagram/
- [ ] https://leetcode.com/problems/assign-cookies/
- [ ] https://leetcode.com/problems/majority-element/description/
- [ ] https://leetcode.com/problems/wiggle-sort-ii/description/
- [ ] https://leetcode.com/problems/majority-element-ii/description/