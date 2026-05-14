class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        i = 0
        k = 0
        while k < len(nums):
            j = k
            while (j < (len(nums) - 1) and nums[j+1] == nums[j]):
                j += 1
            nums[i] = nums[k]
            k = j + 1
            i += 1
        while len(nums) > i:
            nums.pop(-1)


        