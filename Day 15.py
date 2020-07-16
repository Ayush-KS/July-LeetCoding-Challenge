# Reverse Words in a string

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        ans = " "
        return ans.join(words)
        