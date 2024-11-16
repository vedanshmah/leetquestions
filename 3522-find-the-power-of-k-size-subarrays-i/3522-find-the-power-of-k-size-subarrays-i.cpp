class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res(n-k+1,-1);
        int co=1;
        //1st window ans calc
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]+1){
                co++;
            }
            else{
                co=1;
            }
        }
        if(co==k){
            res[0]=nums[k-1];
        }

        int i=1;
        int j=k;
        while(j<n){
            if(nums[j]==nums[j-1]+1){
                co++;
            }
            else{
                co=1;
            }
            if(co>=k){
                res[i]=nums[j];
            }
            i++;
            j++;
        }
        
        return res;
    }
};