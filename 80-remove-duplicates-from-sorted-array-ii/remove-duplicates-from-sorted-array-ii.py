class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        n = len(nums)

        # If size <= 2, already valid
        if n <= 2:
            return n

        # First two elements are always allowed
        k = 2

        for i in range(2, n):

            # Compare with element 2 places behind
            if nums[i] != nums[k - 2]:

                nums[k] = nums[i]
                k += 1

        return k