from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        max_profit = 0
        
        for i in range(n):
            for j in range(i,n):
                profit = prices[j]-prices[i]
                max_profit = max(profit,max_profit)
        
        return max_profit
