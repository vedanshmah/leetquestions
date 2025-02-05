class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> nonequal_pos;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                nonequal_pos.push_back(i);
            }
        }
        if(nonequal_pos.size()==0){
            return true;
        }
        if(nonequal_pos.size()==2){
            swap(s2[nonequal_pos[0]],s2[nonequal_pos[1]]);
            if(s1==s2){
                return true;
            }
        }
        return false;
    }
};