class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=INT_MIN;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        res=sum/k;
        int i=k;
        while(i<nums.size()){
            sum=sum-nums[i-k];
            sum=sum+nums[i];
            double temp=sum/k;
            res=max(res,temp);
            i++;
        }
        return res;
    }
};