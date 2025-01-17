class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res=derived[0];
        for(int i=1;i<derived.size();i++){
            res=res^derived[i];
        }
        if(res==0){
            return true;
        }
        return false;
    }
};