class Solution {
public:
        vector<int> segmin, segmax, lazy;
        int n;
    void propogate(int i,int l,int r){
        if(lazy[i]!=0){
            segmin[i]+=lazy[i];
            segmax[i]+=lazy[i];
            if(l!=r){
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;
        }
    }
    void updatesegtree(int start,int end,int val,int i,int l,int r){
        propogate(i,l,r);
        if(r<start || l>end){
            return;
        }
        if(start<=l && end>=r){
            lazy[i]+=val;
            propogate(i,l,r);
            return;
        }
        int mid=l+(r-l)/2;
        updatesegtree(start,end,val,2*i+1,l,mid);
        updatesegtree(start,end,val,2*i+2,mid+1,r);
        segmin[i] = min(segmin[2*i+1], segmin[2*i+2]);
        segmax[i] = max(segmax[2*i+1], segmax[2*i+2]);
    }

    int recentzero(int i,int l,int r){
        propogate(i,l,r);
        if(segmin[i]>0 || segmax[i]<0){
            return -1;
        }
        if(l==r){
            return l;
        }
        int mid=l+(r-l)/2;
        int leftres=recentzero(2*i+1,l,mid);
        if(leftres!=-1){
            return leftres;
        }
        return recentzero(2*i+2,mid+1,r);
    }

    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        segmin.assign(4*n, 0);
        segmax.assign(4*n, 0);
        lazy.assign(4*n, 0);
        

        
        int maxl=0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            int val=(nums[r]%2==0) ? 1 : -1;
            int prev=-1;
            if(mp.count(nums[r])){
                prev=mp[nums[r]];
            }
            if(prev!=-1){
                updatesegtree(0,prev,-val,0,0,n-1);
            }
            updatesegtree(0,r,val,0,0,n-1);
            int l=recentzero(0,0,n-1);
            if(l!=-1){
                maxl=max(maxl,r-l+1);
            }
            mp[nums[r]]=r;
        }
        return maxl;
    }
};