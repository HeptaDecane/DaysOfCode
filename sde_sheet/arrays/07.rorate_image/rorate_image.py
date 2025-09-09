from typing import *

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        r = len(matrix)
        c = len(matrix[0])
        
        # transpose matrix
        for i in range(r):
            for j in range(i):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
        
        r,c = c,r
        
        # reverse the rows
        for i in range(r):
            matrix[i].reverse()

