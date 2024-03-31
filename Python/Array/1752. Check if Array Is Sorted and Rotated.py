class Solution:
    def check(self, nums: List[int]) -> bool:

        n = len(nums)

        res = 0
        
        for i in range(n):
            if(nums[i] > nums[(i+1)%n]): res += 1
        
        if res > 1: return False

        return True