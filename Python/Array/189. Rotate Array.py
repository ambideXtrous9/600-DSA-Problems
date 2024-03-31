from collections import deque
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:

        Q = deque(nums)

        n = len(nums)

        k = k % n

        for i in range(k):
            temp = Q.pop()
            Q.appendleft(temp)

        for i in range(n):
            nums[i] = Q[i]