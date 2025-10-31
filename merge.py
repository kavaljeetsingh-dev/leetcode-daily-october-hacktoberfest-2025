class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # Step 1: Sort intervals by start time
        intervals.sort(key=lambda x: x[0])  # Or use itemgetter(0) if you prefer
        
        merged = []
        
        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:
                # No overlap, add interval
                merged.append(interval)
            else:
                # Overlap, merge intervals
                merged[-1][1] = max(merged[-1][1], interval[1])
        
        return merged
