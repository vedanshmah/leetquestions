class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int res=0;
        if(n%2 != 0){
            for(int i=0;i<m;i++){
                res=res ^ nums2[i];
            }
        }
        if(m%2 != 0){
            for(int i=0;i<n;i++){
                res=res ^ nums1[i];
            }
        }
        return res;
    }
};