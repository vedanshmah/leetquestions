class Solution {
public:
    int countsubsets(int index,int curror,int maxor,vector<int>& nums){
        //base case
        if(index==nums.size()){
            if(curror==maxor){
                return 1;
            }
            return 0;
        }
        //rec
        int x=countsubsets(index+1,curror | nums[index],maxor,nums);
        int y=countsubsets(index+1,curror,maxor,nums);

        return x+y;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int i=0;i<nums.size();i++){
            maxor=maxor | nums[i];
        }
        int curror=0;
        return countsubsets(0,curror,maxor,nums);
    }
};