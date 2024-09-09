class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        nextGreater = {}
        stack = []
        for i in range(len(nums2)-1, -1, -1):
            while len(stack) > 0 and nums2[i] >= stack[-1]:
                stack.pop()
            
            if len(stack) == 0:
                nextGreater[nums2[i]] = -1
            else:
                nextGreater[nums2[i]] = stack[-1]

            stack.append(nums2[i])

        ans = []
        for n in nums1:
            ans.append(nextGreater[n])
        
        print(ans)
        return ans





s = Solution()
nums1 = [4,1,2]
nums2 = [1,3,4,2]
s.nextGreaterElement(nums1, nums2)

nums1 = [2,4]
nums2 = [1,2,3,4]
s.nextGreaterElement(nums1, nums2)

            


