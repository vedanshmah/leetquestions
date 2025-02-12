class Solution {
public:
    int digsum(int n){
        int res=0;
        while(n){
            int rem=n%10;
            res+=rem;
            n/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            int digisum=digsum(nums[i]);
            if(mp.find(digisum)!=mp.end()){
                int temp=mp[digisum]+nums[i];
                res=max(res,temp);
                mp[digisum]=max(mp[digisum],nums[i]);
            }
            else{
                mp[digisum]=nums[i];
            }
        }
        return res;
    }
};