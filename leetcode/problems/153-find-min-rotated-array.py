class Solution:     
    def searchPeak(self, nums: list[int]) -> int:
        l = 0
        r = len(nums)-1

        while l <= r:
            mid = (l+r)//2
            print(l, mid, r)
            if nums[mid] > nums[mid+1]:
                return mid
            if nums[l] <= nums[mid]:
                l = mid + 1
            else:
                r = mid - 1
        
        return r

    def findMin(self, nums: list[int]) -> int:
        if nums[-1] >= nums[0]:
            return nums[0]
        
        peak = self.searchPeak(nums)
        print(peak)
        return nums[peak+1]
    

S = Solution()

print(S.findMin([11]))
print(S.findMin([11,13,15,17]))

print(S.findMin([4,5,6,7,0,1,2]))
print(S.findMin([7,8,9,1,2,3,4,5,6]))
print(S.findMin([3,4,5,1,2]))
print(S.findMin([4,5,1,2,3]))


