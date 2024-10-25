class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> fold(folder.begin(),folder.end());
        vector<string> ans;
        for(int i=0;i<folder.size();i++){
            string tempfolder=folder[i];
    
            bool found=false;
            while(!tempfolder.empty()){
                size_t pos=tempfolder.find_last_of('/');
                tempfolder=tempfolder.substr(0,pos);
                if(fold.find(tempfolder)!=fold.end()){
                    found=true;
                }
            }
            if(found==false){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};