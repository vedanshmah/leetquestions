class Solution {
public:
    vector<int> NGR(vector<int>& nums,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()){
                if(i<n) res[i%n]=-1;
            }else{
                while(!st.empty() && st.top()<=nums[i%n]){
                    st.pop();
                }
                if (i<n){
                    res[i%n]=st.empty() ? -1 : st.top();
                } 
            }
            st.push(nums[i%n]);
        }
        return res;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        return NGR(nums,nums.size());
    }
};