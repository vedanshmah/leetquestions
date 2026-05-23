class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalop=INT_MAX;
        // int temp=0;
        int x=0;
        while(x<k){
            int y=0;
            while(y<k){
                int temp=0;
                if(x==y){
                    y++;
                    continue;
                } 
                for(int i=0;i<nums.size();i++){
                    if((i)%2!=0){
                        int mod=nums[i]%k;
                        temp+=min(abs(mod-y),k-abs(mod-y));
                    }else if((i)%2==0){
                        int mod=nums[i]%k;
                        temp+=min(abs(mod-x),k-abs(mod-x));
                    }
                }
                totalop=min(totalop,temp);
                y++;
            }
            
            x++;
        }
        return totalop;
    }
};