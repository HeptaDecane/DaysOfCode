from typing import *
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        i=j=k=0
        result = [None]*(n+m)
        
        while i<m and j<n:
            
            if nums1[i] < nums2[j]:
                result[k] = nums1[i]
                i = i+1
            
            else:
                result[k] = nums2[j]
                j = j+1
            
            k = k+1
        
        
        if i<m:
            result[k:] = nums1[i:m]
        elif j<n:
            result[k:] = nums2[j:n]
            
        
        
        nums1[0:m] = result[0:m]
        nums1[m:m+n] = result[m:m+n]
