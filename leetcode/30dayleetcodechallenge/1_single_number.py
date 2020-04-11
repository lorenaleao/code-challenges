class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        unique_numbers = set()
        for elem in nums: # O(n)
            if elem not in unique_numbers: # in set/dict - Average: O(1), Worst: O(n)
                unique_numbers.add(elem) # Average: O(1), Worst: O(n)
            else:
                unique_numbers.remove(elem) # Average: O(1), Worst: O(n)
        return unique_numbers.pop()
        