class Solution(object):

  def moveZeroes(self, nums):
    """Do not return anything, modify nums in-place instead.

    :type nums: List[int]
    :rtype: None
    """
    last_non_zero_found_at = 0

    # Move all non-zero elements to the front
    for i in range(len(nums)):
      if nums[i] != 0:
        nums[last_non_zero_found_at], nums[i] = (
            nums[i],
            nums[last_non_zero_found_at],
        )
        last_non_zero_found_at += 1