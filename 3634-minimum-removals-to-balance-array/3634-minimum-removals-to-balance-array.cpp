class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        int kept=0;
        int n= nums.size();
        //for(int i=0;i<n;i++){ 
        //    int j=i;
        //    while(j<n && (nums[j]<=(long long)nums[i]*k)){  
        //        kept=max(kept,j-i+1);
        //        j++;
        //    }
        //}
        int i=0;
        for(int j=0;j<n;j++){
            while(nums[j]>(long long)nums[i]*k){
                i++;
            }
            kept=max(kept,j-i+1);
        }
        return n-kept;
    }
};


