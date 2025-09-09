from typing import *
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        # rotate array to bring zeroes to front
        nums1[:] = nums1[m:] + nums1[:m]
        
        i=j=k=0
        while i<m and j<n:
            num1 = nums1[n+i]
            num2 = nums2[j]
            
            if num1 < num2:
                nums1[k] = num1
                i = i+1
                
            else: 
                nums1[k] = num2
                j = j+1
            
            k = k+1
        
        if i<m:
            nums1[k:] = nums1[n+i:]

        if j<n:
            nums1[k:] = nums2[j:]
                        
        
        
Solution().merge([1,2,0,0,0],2,[2,5,6],3)
