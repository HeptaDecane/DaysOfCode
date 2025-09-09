class Solution:
    
    def ncr(self, n,r):
        '''
        ncr = n! / (r! * (n-r)!)
        6c3 = 1.2.3.4.5.6 / (1.2.3 * 1.2.3)
        6c3 = 4.5.6 / 1.2.3
        '''
        res = 1
        for i in range(r):
            res = res * (n-i)//(i+1)
    
        return res


temp=Solution().ncr(30,9)
