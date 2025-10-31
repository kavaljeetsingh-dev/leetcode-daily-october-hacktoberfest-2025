from collections import Counter 
class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        n=len(nums)

        if n%k!=0:
            return False

        groups= n//k
        freq=Counter(nums)

        for count in freq.values():
            if count> groups:
                return False
        return True        
            
