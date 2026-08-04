class Solution(object):

  def maxProfit(self, prices):
    """Do not return anything, return max profit integer.

    :type prices: List[int]
    :rtype: int
    """
    min_price = float('inf')
    max_profit = 0

    for price in prices:
      if price < min_price:
        min_price = price
      elif price - min_price > max_profit:
        max_profit = price - min_price

    return max_profit