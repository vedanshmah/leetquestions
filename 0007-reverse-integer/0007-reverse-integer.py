class Solution(object):
    def reverse(self, x):
        ans=0
        sign=0
        if(x<0):
            sign=-1
        else:
            sign=1
        x=abs(x)
        while(x):
            rem=x%10
            ans=ans*10+rem
            x=x//10
        ans=ans*sign
        if(ans<-2**31 or ans>2**31-1):
            return 0
        return ans
        """
        :type x: int
        :rtype: int
        """
        