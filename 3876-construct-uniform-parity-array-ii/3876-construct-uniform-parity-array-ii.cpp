class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int firsteven=INT_MAX,firstodd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                firsteven=min(nums1[i],firsteven);
                
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                firstodd=min(nums1[i],firstodd);
               
            }
        }
        if(firsteven == INT_MAX || firstodd == INT_MAX) return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]-firstodd<1){
                return false;
            }
        }

        return true;
    }
};