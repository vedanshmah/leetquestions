class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0,temp;
        while(true){
            unordered_map<int,int> mp;
            temp=0;
            for(int i=0;i<nums.size();i++){
                if(++mp[nums[i]]==2){
                    temp++;
                }
            }
            
            if(temp==0){
                break;
            }
            nums.erase(nums.begin(),nums.begin()+min(3,(int)nums.size()));
            ans++;
        }
        return ans;
    }
};