class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        sol = 0
        i = 0
        while (i < len(s)):
            current_digit = dict[s[i]]
            next_digit = dict[s[i+1]] if i+1 < len(s) else 0
            if(current_digit < next_digit):
                sol -= current_digit
                sol += next_digit
                i += 2
            else:
                sol += current_digit
                i += 1
        return sol
        