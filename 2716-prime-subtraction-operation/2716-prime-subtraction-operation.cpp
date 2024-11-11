class Solution {
public:
    bool isprime[1000];
    void sieve_prime(){
        fill(isprime,isprime+1000,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<1000;i++){
            if(isprime[i]==true){
                for(int j=i*i;j<1000;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        sieve_prime();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }

            for(int j=2;j<nums[i];j++){
                if(isprime[j]==false){
                    continue;
                }
                if(nums[i]-j < nums[i+1]){
                    nums[i]=nums[i]-j;
                    break;
                }
            }
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};