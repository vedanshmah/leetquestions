class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int nwhite=0;
        int s=0;
        int e=0;
        while(e<k){
            if(blocks[e]=='W'){
                nwhite++;
            }
            e++;
        }
        int res;
        res=nwhite;
        while(e<blocks.size()){
            if(blocks[s]=='W'){
                nwhite--;
            }
            if(blocks[e]=='W'){
                nwhite++;
            }
            res=min(res,nwhite);
            e++;
            s++;
        }
        return res;
    }
};