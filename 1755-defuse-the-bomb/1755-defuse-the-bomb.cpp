class Solution {
public:
    int greater(vector<int>& code, int k,int idx,int n){
        int ans=0;
        
        for(int i=1;i<=k;i++){
            ans+=code[(idx+i)%n];
        }
        return ans;
    }
    int smaller(vector<int>& code, int k,int idx,int n){
        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=code[(idx-i+n)%n];
        }
        return ans;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(),0);
        int n=code.size();
        if(k>0){
            for(int i=0;i<n;i++){
                res[i]=greater(code,k,i,n);
            } 
        }
        if(k<0){
            for(int i=0;i<n;i++){
                res[i]=smaller(code,abs(k),i,n);
            }
        }
        return res;
    }
    
};