# 35. Search Insert Position
# https://leetcode.com/problems/search-insert-position/

from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # 7 // 2 == 3
        # 8 // 2 == 4
        left, right = 0, len(nums) - 1
        
        while left <= right:
            # mid = left + (right - left) // 2
            mid = (left + right) // 2

            if nums[mid] == target: 
                return mid
            if nums[mid] < target: 
                left = mid + 1
                if right < left: return left
            elif nums[mid] > target:
                right = mid - 1
                if right < 0: return 0
        
        return mid

s = Solution();
print(s.searchInsert([1, 3], 2))

print(f"1 // 2 = {1 + (1 - 1) // 2}")