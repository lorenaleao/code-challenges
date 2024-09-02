class Solution:
    def removeNonAlphaNumeric(self, s: str) -> str:
        new_s = ""
        for c in s:
            if (ord(c) >= ord('a') and ord(c) <= ord('z')) or (ord(c) >= ord('A') and ord(c) <= ord('Z')) or (ord(c) >= ord('0') and ord(c) <= ord('9')):
                new_s += c
        return new_s
    
    def lowerCase(self, s: str) -> str:
        new_s = ""
        for c in s:
            if (ord(c) >= ord('A') and ord(c) <= ord('Z')):
                new_s += chr(ord(c) + 32)
            else:
                new_s += c
        return new_s

    def isPalindrome(self, s: str) -> bool:
        strippedS = self.lowerCase(self.removeNonAlphaNumeric(s))
        
        l = 0
        r = len(strippedS) - 1
        while l <= r:
            if strippedS[l] != strippedS[r]:
                return False
            l += 1
            r -= 1
        
        return True
                
s = Solution()
print(s.isPalindrome("A man, a plan, a canal: Panama"))
print(s.isPalindrome("race a car"))
print(s.isPalindrome(" "))
print(s.isPalindrome(""))
print("0P", s.isPalindrome("0P"))