class Solution:
    def searchStandard(self, nums: list[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                l = mid+1
            else:
                r = mid-1

        return -1
     
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

    def search1(self, nums: list[int], target: int) -> int:
        if nums[-1] >= nums[0]:
            return self.searchStandard(nums, target)
        
        peak = self.searchPeak(nums)
        print(f"peak: {peak}")
        ans = self.searchStandard(nums[:peak+1], target)
        print(f"ans: {ans}")
        if ans != -1:
            return ans
        
        ans = self.searchStandard(nums[peak+1:], target)
        if ans == -1:
            return ans
        print(f"ans: {ans}")
        return peak+ans+1
    
    def search2(self, nums: list[int], target: int) -> int:
        if nums[-1] >= nums[0]:
            return self.searchStandard(nums, target)
        
        peak = self.searchPeak(nums)
        peak = self.searchStandard(nums[:peak+1], target)
        # IMPLEMENT ME
        return peak
    

S = Solution()

print(S.search1([4,5,6,7,0,1,2], 0))
print(S.search1([7,8,9,1,2,3,4,5,6], 7))
print(S.search1([4,5,6,7,0,1,2], 3))
print(S.search1([1], 0))


