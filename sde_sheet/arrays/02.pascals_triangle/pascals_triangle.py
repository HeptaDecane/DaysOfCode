from typing import *


class Solution:
    
    def generate_row(self, n):
        row = [1]
        for i in range(1,n):
            cell = row[i-1]*(n-i)//i
            row.append(cell)
        
        return row
    
    def generate(self, n: int) -> List[List[int]]:
        rows = []
        
        for i in range(1,n+1):
            row = self.generate_row(i)
            rows.append(row)
        
        return rows