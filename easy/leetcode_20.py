class Solution: 
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s: 
            if (c == "(" or c == "[" or c == "{"): stack.append(c)
            else:
                if (c == ')'):
                    if (not stack or stack.pop() != '('): return False;
                if (c == ']'):
                    if (not stack or stack.pop() != '['): return False;
                if (c == '}'):
                    if (not stack or stack.pop() != '{'): return False;

        return True if not stack else False

s = Solution()
print(s.isValid("["))