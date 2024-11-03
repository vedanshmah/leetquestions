class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(s.length()!=goal.length()){
            return false;
        }
        string storage=s+s;
        //int j=0;
        //for(int i=0;i<n;i++){
        //    storage[n+i]=s[i];
        //}
        if(storage.find(goal)!=string::npos){
            return true;
        }
        
        return false;
        
    }
};