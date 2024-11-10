class Solution {
public:
    void addinwindow(int val,vector<int>& vec){
        for(int i=0;i<32;i++){
            if(((val>>i) & 1) == 1){
                vec[i]++;
            }
        }
    }
    void removefromwindow(int val,vector<int>& vec){
        for(int i=0;i<32;i++){
            if(((val>>i) & 1) == 1){
                vec[i]--;
            }
        }
    }
    int decimalformed(vector<int>& vec){
        int ans=0;
        for(int i=0;i<32;i++){
            if(vec[i]>0){
                ans=ans | (1<<i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int res=INT_MAX;
        vector<int> vec(32,0);
        while(j<n){
            //grow
            addinwindow(nums[j],vec);

            //shrink
            while(i<=j && decimalformed(vec)>=k){
                res=min(res,j-i+1);
                removefromwindow(nums[i],vec);
                i++;
            }
            //ans calc
            j++;
        }
        if(res!=INT_MAX){
            return res;
        }
        else{
            return -1;
        }
    }
};