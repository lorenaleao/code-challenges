class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n = len(temperatures)
        stack = []
        ans = [0] * n
        print(temperatures)

        for i in range(n-1, -1, -1):
            while len(stack) > 0 and temperatures[i] >= temperatures[stack[-1]]:
                stack.pop()

            # if len(stack) == 0:
            #    ans[i] = 0  # nothing changes
            if len(stack) > 0 and temperatures[i] < temperatures[stack[-1]]:
                ans[i] = stack[-1] - i
            
            stack.append(i)

            print(stack)
        
        print(ans)

s = Solution()
temperatures = [73,74,75,71,69,72,76,73]
# Output: [1,1,4,2,1,1,0,0]
s.dailyTemperatures(temperatures)

temperatures = [30,40,50,60]
# Output: [1,1,1,0]
s.dailyTemperatures(temperatures)

temperatures = [30,60,90]
# Output: [1,1,0]
s.dailyTemperatures(temperatures)

