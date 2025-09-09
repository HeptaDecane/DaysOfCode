from typing import *
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        i=m-1
        j=0
        
        while i>=0 and j<n:
            if nums1[i] > nums2[j]:
                nums1[i],nums2[j] = nums2[j],nums1[i]
                i = i-1
                j = j+1
                
            else: break
                        
        nums1[m:] = nums2[:n]
        nums1[:] = sorted(nums1[:m]) + sorted(nums1[m:])
        
        
Solution().merge([1,2,0,0,0],2,[2,5,6],3)
