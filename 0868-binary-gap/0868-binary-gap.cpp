class Solution {
public:
    int binaryGap(int n) {
        string bin="";
        int temp=n;
        while(temp){
            int rem=temp%2;
            bin.push_back(rem+'0');
            temp/=2;
        }
        reverse(bin.begin(),bin.end());
        vector<int> vec;
        for(int i=0;i<bin.size();i++){
            if(bin[i]=='1'){
                vec.push_back(i);
            }
        }
        int ans=0;
        for(int i=1;i<vec.size();i++){
            ans=max(ans,vec[i]-vec[i-1]);
        }
        return ans;
    }
};