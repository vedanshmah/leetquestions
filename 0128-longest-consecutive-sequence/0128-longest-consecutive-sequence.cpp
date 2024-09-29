class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int current=1;
        int largest=0;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                if(nums[i]==(nums[i-1]+1)){
                    current++;
                }
                else{
                    largest=max(largest,current);
                    current=1;
                }
            }
        }
        return max(largest,current);
    }
};