class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> records;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            int rem=arr[i]%k;
            if(rem<0){
                rem=rem+k;
            }
            records[rem]++;
        }

        for(auto& [rem,co] : records){
            if(rem==0){
                if(co%2 != 0){
                    return false;
                }
            }
            else{
                int dusra_part=k-rem;
                if(records[rem] != records[dusra_part]){
                    return false;
                }
            }
        }
        return true;
    }
};