class Solution {
public:
    int numRabbits(vector<int>& answers) { 
        unordered_map<int,int> mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int rabbits=0;
        for(auto it:mp){
            if(it.first==0){
                rabbits+=it.second;
            }
            else{
                int groupsize=it.first+1;
                int groups=(it.second+groupsize-1)/groupsize;
                rabbits+=groups*groupsize;
            }
        }
        return rabbits;
    }
};