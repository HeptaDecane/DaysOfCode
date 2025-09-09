class Solution:

    def generate_row(self, n):
        '''
        row(6)
        1 
        5   =   5/1
        10  =   5.4/1.2
        10  =   5.4.3/1.2.3
        5   =   5.4.3.2/1.2.3.4
        1   =   5.4.3.2.1/1.2.3.4.5
        '''
        
        row = [1]
        for i in range(1,n):
            cell = row[i-1]*(n-i)//i
            row.append(cell)
        
        return row
    

temp=Solution().generate_row(8)
