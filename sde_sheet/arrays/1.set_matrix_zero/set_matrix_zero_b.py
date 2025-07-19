# https://leetcode.com/problems/set-matrix-zeroes/
from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        
        blank_row = False
        blank_col = False
        
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    matrix[0][j]=0
                    matrix[i][0]=0
                    
                    if i==0: blank_row=True
                    if j==0: blank_col=True
                    
        for i in range(1,rows):
            for j in range(1,cols):
                if matrix[i][0]==0 or matrix[0][j]==0:
                    matrix[i][j]=0
        
        if blank_row:
            for j in range(cols):
                matrix[0][j]=0
        
        if blank_col:
            for i in range(rows):
                matrix[i][0]=0
        
        



'''
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
'''