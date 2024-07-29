class Solution:
    def searchStandard(self, nums: list[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return target
            if nums[mid] < target:
                l = mid+1
            else:
                r = mid-1

        return -1
    
    def searchSqrt(self, target: int) -> int:
        l = 0
        r = target//2+1

        while l <= r:
            mid = (l+r)//2
            if mid*mid == target:
                return mid
            if mid*mid < target:
                l = mid+1
            else:
                r = mid-1

        return r
    
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        return self.searchSqrt(x)
    

S = Solution()

for i in range(26):
    print(f"sqrt({i}): {S.mySqrt(i)}")
