# https://claude.ai/chat/14a8cf7c-be3e-4566-90c8-4aa827ee7077
import heapq

class Solution:
    def signal_ping(self,pings):
        
        n = len(pings)
        signals = [0]*n
        result = []
        
        for idx in pings:
            signals[idx-1] = 1
            stat = signals[0:n]
            sweeps = 0
            
            while True:
                swapped = False
                for i in range(n-1):
                    if stat[i]==1 and stat[i+1]==0:
                        stat[i],stat[i+1] = stat[i+1],stat[i]
                        swapped = True
                
                sweeps += 1
                if not swapped: break

            result.append(sweeps)
        
        return result


pings = [1,2,4,3]
res = Solution().signal_ping(pings)
