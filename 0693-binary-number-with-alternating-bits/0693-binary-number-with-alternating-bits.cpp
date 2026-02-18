class Solution {
public:
    string res;
    void dectobin(int n){
        while(n){
            int rem=n%2;
            res.push_back(rem+'0');
            n/=2;
        }
    }
    bool hasAlternatingBits(int n) {
        res="";
        dectobin(n);
        for(int i=1;i<res.size();i++){
            if(res[i]==res[i-1]){
                return false;
            }
        }
        return true;
    }
};