class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long int res=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if((long long )(nums[i]-nums[j])*nums[k] > 0){
        //                 res=max(res , (long long )(nums[i]-nums[j])*nums[k]);
        //             }
        //         }
        //     }
        // }
        // return res;

        long long maxele=0,maxdiff=0;
        for(int i=0;i<n;i++){
            res=max(res,(long long)(maxdiff*nums[i]));
            maxdiff=max(maxdiff,(long long)(maxele-nums[i]));
            maxele=max(maxele,(long long)nums[i]);
        }
        return res;
    }
};