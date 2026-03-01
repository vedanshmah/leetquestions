class Solution {
public:
    int minPartitions(string n) {
        int co=0;
        while(true){
            bool allzero=true;
            
            for(int i=0;i<n.size();i++){
                if(n[i]>'0'){
                    n[i]=n[i]-1;
                    allzero=false;
                }
            }
            if(allzero){
                break;
            }
            co++;
        }
        return co;
    }
};
