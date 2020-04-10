class Solution:
    def reverseWords(self, s: str) -> str:
        s=list(s.strip().split())
        s.reverse()
        return ' '.join(s)
