# https://claude.ai/chat/138ce390-9c76-4478-804a-42f2e7e7491e
import heapq

class Solution:
    def max_revenue(quantities, m):
        max_heap = [-q for q in quantities]
        heapq.heapify(max_heap)
        
        revenue = 0
        
        for i in range(m):
            if not max_heap: break
            
            max_quantity = -heapq.heappop(max_heap)
            revenue += max_quantity
            
            current_quantity = max_quantity-1
            if current_quantity > 0:
                heapq.heappush(max_heap,-current_quantity)
        
        return revenue