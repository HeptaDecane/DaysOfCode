from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        n = len(prices)
        i = j = 0
        max_profit = 0
        
        for j in range(n):
            profit = prices[j]-prices[i]
            max_profit = max(profit, max_profit)
            if profit < 0: i=j
            
        return max_profit
    