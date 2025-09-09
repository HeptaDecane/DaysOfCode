from typing import *
import math

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        nums1[m:] = nums2[0:n]
        l = m+n
        
        gap = math.ceil(l/2)
        
        while True:
            i=0
            j=gap
            
            while j<l:
                if nums1[i] > nums1[j]:
                    nums1[i],nums1[j] = nums1[j],nums1[i]
                
                i = i+1
                j = j+1
            
            if gap==1: break
            else: gap = math.ceil(gap/2)

        
        
        
Solution().merge([1,6,0,0,0],2,[2,2,5],3)

