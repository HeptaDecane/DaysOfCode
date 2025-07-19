from typing import *
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        n = len(nums)
        global_max_sum = -math.inf
        
        for i in range(n):
            local_max_sum = -math.inf
            sum = 0
            for j in range(i,n): 
                sum = sum + nums[j]
                local_max_sum = max(sum, local_max_sum)
                
            global_max_sum = max(local_max_sum, global_max_sum)
        
        return global_max_sum

            