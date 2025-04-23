class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            int num=i;
            int sum=0;
            while(num>0){
                int rem=num%10;
                sum+=rem;
                num/=10;
            }
            mp[sum]++;
        }
        int maxco=0;
        for(auto it:mp){
            maxco=max(maxco,it.second);
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==maxco){
                ans++;
            }
        }
        return ans;
    }
};