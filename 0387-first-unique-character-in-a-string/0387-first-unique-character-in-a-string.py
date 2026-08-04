import collections


class Solution(object):

  def firstUniqChar(self, s):
    """
        :type s: str
        :rtype: int
        """
    count = collections.Counter(s)

    # Find the index of the first character with a frequency of 1
    for i, char in enumerate(s):
      if count[char] == 1:
        return i

    return -1