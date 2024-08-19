class Solution:
    def removeElementFirst(self, nums: list[int], val: int) -> int:
        if len(nums) <= 0:
            return 0

        j = 0
        i = len(nums)-1
        while i > j:
            if nums[i] != val:
                nums[i], nums[j] = nums[j], nums[i]
                j+=1
            else:
                i-=1
        
        #print(i, j, len(nums)-(i+1))
        if nums[i] == val:
            return i
        return i+1

    def removeElement(self, nums: list[int], val: int) -> int:
        index = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[index] = nums[i]
                index += 1
        return index

