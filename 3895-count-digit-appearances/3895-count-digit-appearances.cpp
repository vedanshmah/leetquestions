class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int no=nums[i];
            while(no){
                if(no%10==digit){
                    ans++;
                }
                no/=10;
            }
        }
        return ans;
    }
};