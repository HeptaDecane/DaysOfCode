from typing import *

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        
        '''
        [0 - low-1] => 0
        [low - mid-1] => 1
        [mid - high] => unsorted
        [high+1 - n-1] => 2
        '''
        
        n = len(nums)
        low = mid = 0
        high = n-1
        
        while mid <= high:
            if nums[mid] == 0:
                nums[low],nums[mid] = nums[mid],nums[low]
                low = low+1
                mid = mid+1
            
            elif nums[mid] == 1:
                mid = mid+1
            
            else:
                nums[mid],nums[high] = nums[high],nums[mid]
                high = high-1
            
    