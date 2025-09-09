# https://leetcode.com/problems/set-matrix-zeroes/
from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        
        row_map = [False]*rows
        col_map = [False]*cols
        
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j]==0:
                    row_map[i] = True
                    col_map[j] = True
        
        for i in range(rows):
            for j in range(cols):
                if row_map[i] or col_map[j]:
                    matrix[i][j]=0
