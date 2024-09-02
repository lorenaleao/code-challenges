class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        unique = 0
        curr = 1
        eqCount = 1
        print(nums)
        while curr < len(nums):
            print(f"(u, c, eq): ({unique}, {curr}, {eqCount})")
            if nums[unique] != nums[curr] and eqCount == 2:
                unique = curr
                curr += 1
                eqCount = 1
            elif nums[unique] != nums[curr] and curr > unique+2:
                nums[unique+2] = nums[curr]
                unique = curr-1
                curr += 1
                print(nums)

            else:
                eqCount += 1
                curr += 1
        return unique+1

s = Solution()
print(s.removeDuplicates([1,1,1,2,2,3]))
print(s.removeDuplicates([0,0,1,1,1,1,2,3,3]))
# [1,1,2,2,2,3]
#      u 
#            c
#  0 1 2 3 4 5