class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        open = ['(','{','[']
        close = [')','}',']']
        if len(s) % 2 != 0:
            return False
        else:
            for char in s:
                if char in open:
                    stack.append(open.index(char))
                else:
                    if len(stack) == 0:
                        return False
                    elif close.index(char) == stack[-1]:
                        stack.pop()
                    else:
                        return False
            if len(stack) != 0:
                return False
            else:
                return True



        