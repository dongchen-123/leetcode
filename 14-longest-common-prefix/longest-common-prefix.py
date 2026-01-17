class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        i = 0
        while (i < len(strs[0])):
            letter = strs[0][i]
            for word in strs:
                if (i >= len(word) or word[i] != letter):
                    return strs[0][:i]
            i += 1
        prefix = strs[0][:i]
        return prefix
        