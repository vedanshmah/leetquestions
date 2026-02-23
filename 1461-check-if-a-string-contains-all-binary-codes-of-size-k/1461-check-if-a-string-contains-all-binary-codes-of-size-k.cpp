class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()){
            return false;
        }
        int n=1<<k;
        vector<bool> vec(n,false);
        for(int i=0;i<=s.size()-k;i++){
            string sub=s.substr(i,k);
            int idx=stoi(sub,nullptr,2);
            vec[idx]=true;
        }
        for(int i=0;i<vec.size();i++){
            if(!vec[i]){
                return false;
            }
        }
        return true;
    }
};
