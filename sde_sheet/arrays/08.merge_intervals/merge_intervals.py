from typing import *

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        result = []
        n = len(intervals)
        
        intervals.sort()
        start,end = intervals[0]
        
        for i in range(n):
            x,y = intervals[i]
            
            if x<=end and y>=end:
                end = y
                
            elif x>end:
                result.append([start,end])
                start,end=x,y
        
        
        # append the last merged interval
        result.append([start,end])
        return result
