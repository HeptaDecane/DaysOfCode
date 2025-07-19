from typing import *

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        
        n = len(nums)
        zeroes = ones = twos = 0
        
        for num in nums:
            if num == 0: zeroes += 1
            elif num == 1: ones += 1
            else: twos += 1
            
        
        nums[0:zeroes] = [0]*zeroes
        nums[zeroes:zeroes+ones] = [1]*ones
        nums[zeroes+ones:n] = [2]*twos
    