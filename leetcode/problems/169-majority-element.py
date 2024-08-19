class Solution:
    # if the array is sorted, is easier to count and not use extra space
    def majorityElementLinearExtraSpace(self, nums: list[int]) -> int:
        maxCount = -1
        majElem = 0
        countDict = {}
        for e in nums:
            if e in countDict:
                countDict[e] += 1
            else: 
                countDict[e] = 1
            
            if countDict[e] > maxCount:
                maxCount = countDict[e]
                majElem = e
        
        return majElem

    # Boyer–Moore majority vote algorithm
    # https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    def majorityElement(self, nums: list[int]) -> int:
        candidate = count = 0
        
        for n in nums:
            if count == 0:
                candidate = n
            count += 1 if n == candidate else -1
        
        return candidate