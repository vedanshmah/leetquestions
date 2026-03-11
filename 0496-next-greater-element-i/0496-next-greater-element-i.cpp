class Solution {
public:
    vector<int> NGR(vector<int>& nums2,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=-1;
            }else{
                while(!st.empty() && nums2[st.top()]<=nums2[i]){
                    st.pop();
                }
                res[i]=st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        for(int i=0;i<res.size();i++){
            cout<<res[i];
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngr=NGR(nums2,nums2.size());
        vector<int> res(nums1.size());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    if(ngr[j]==-1){
                        res[i]=-1;
                    }else{
                        res[i]=nums2[ngr[j]];
                    }
                }
            }
        }
        return res;
    }
};

