class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int LM[n];
        int RM[n];

        LM[0]=nums[0];
        for(int i=1;i<n;i++){
            LM[i]=min(LM[i-1],nums[i]);
        }

        RM[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            RM[j]=max(RM[j+1],nums[j]);
        }

        for(int i=0;i<n;i++){
            if((LM[i]<nums[i]) && (nums[i]<RM[i])){
                return true;
            }
        }
        return false;
    }
};