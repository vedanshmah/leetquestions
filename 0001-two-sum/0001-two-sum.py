class Solution(object):
    def twoSum(self, nums, target):
        dic={}
        n=len(nums)
        for i in range (0,n):
            req=target-nums[i]
            if req in dic:
                return (dic[req],i)
            dic[nums[i]]=i
        return []
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        