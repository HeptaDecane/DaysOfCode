class Solution:
    
    def ncr(self, n, r):
        res = 1
        for i in range(r):
            res = res * (n-i)//(i+1)
    
        return res


    def generate_row(self, n):
        row=[]
        for i in range(n):
            cell = self.ncr(n-1,i)
            row.append(cell)
        
        return row

temp=Solution().generate_row(7)
