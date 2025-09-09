class Solution:
    
    def ncr(self, n,r):
        '''
        ncr = n! / (r! * (n-r)!)
        '''
        _n = 1
        for i in range(1,n+1):
            _n = _n*i
        
        _r = 1
        for i in range(1,r+1):
            _r = _r*i
        
        _nr = 1
        for i in range(1,n-r+1):
            _nr = _nr*i
        
        return _n/(_r*_nr)
    


temp=Solution().ncr(7,2)
