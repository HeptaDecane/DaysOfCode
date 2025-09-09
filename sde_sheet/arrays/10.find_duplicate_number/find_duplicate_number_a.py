from typing import *

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        n = len(nums)
        num_map = [0]*n
        
        for num in nums:
            if num_map[num]: return num
            else: num_map[num] = 1
