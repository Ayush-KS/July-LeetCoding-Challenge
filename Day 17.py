# Top K Frequent Elements

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for i in nums:
            freq[i] = freq.get(i, 0) + 1
        freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        
        ans = []
        for x in range(k):
            ans.append(freq[x][0])
        return ans