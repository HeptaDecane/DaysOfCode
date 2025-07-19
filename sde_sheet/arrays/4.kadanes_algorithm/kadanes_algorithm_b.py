from typing import *
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        n = len(nums)
        max_sum = -math.inf
        sum = 0
        local_start = 0
        start = 0
        end = 0
        
        for i in range(n):
            
            if sum == 0:
                local_start = i
            
            sum = sum + nums[i]
            
            if sum > max_sum:
                max_sum = sum
                start = local_start
                end = i
            
            sum = max(0,sum)
        
        return max_sum


Solution().maxSubArray([-2,-3,4,-1,-2,1,5,-3])
            