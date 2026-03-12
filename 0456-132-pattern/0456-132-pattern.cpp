class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int nums3=INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums3){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                nums3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
// we start from n-1 -> 0  because nums2 and nums 3 should be greater ones to satify .. nums[k]<nums[j]
// the moment we find nums[i]<nums[k]... we find our required subsequence..
// we store max element in stack bottom .. then smaller ontop 
// the moment we find an elemnt greater than top of stack element we consider it as num2 and top ele as num3 thats why we update nums3=top and pop it till stack is empty 
// the moment we find nums[i] < nums3 we are done as nums3 is already <nums2 