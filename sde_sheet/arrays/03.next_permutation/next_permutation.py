from typing import *

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        
        n = len(nums)
        
        idx = -1
        for i in range(n-1,0,-1):
            if nums[i] > nums[i-1]:
                idx = i-1
                break
    
        if idx < 0:
            nums.reverse()
            return
        
        for i in range(n-1,idx,-1):
            if nums[i] > nums[idx]:
                nums[i],nums[idx] = nums[idx],nums[i]
                break
            
        nums[idx+1:n] = reversed(nums[idx+1:n])
        


nums = [2,1,5,4,3,0,0]
Solution().nextPermutation(nums)
print(nums)
