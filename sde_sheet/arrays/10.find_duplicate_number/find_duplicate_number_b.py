from typing import *

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        slow = nums[0]
        fast = nums[0]
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast: break
            
        start = nums[0]
        while start!=slow:
            start = nums[start]
            slow = nums[slow]
            
        return start
        