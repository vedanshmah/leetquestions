class NumArray {
public:
    int n;
    vector<int> st;
    void buildst(int i,int l,int r,vector<int>& nums){
        //base
        if(l==r){
            st[i]=nums[l];
            return;
        }
        //rec
        int mid=l+(r-l)/2;
        buildst(2*i+1,l,mid,nums);
        buildst(2*i+2,mid+1,r,nums);
        st[i]=st[2*i+1]+st[2*i+2];
    }

    void updatest(int idx,int val,int i,int l,int r){
        //base
        if(l==r){
            st[i]=val;
            return;
        }
        //rec
        int mid=l+(r-l)/2;
        if(mid>=idx){
            updatest(idx,val,2*i+1,l,mid);
        }
        else{
            updatest(idx,val,2*i+2,mid+1,r);
        }
        st[i]=st[2*i+1]+st[2*i+2];
    }

    int querysum(int start,int end,int i,int l,int r){
        if(l>end || r<start){
            return 0;
        }
        if(start<=l && end>=r){
            return st[i];
        }
        int mid=l+(r-l)/2;
        return querysum(start,end,2*i+1,l,mid) +querysum(start,end,2*i+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n);
        buildst(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updatest(index,val,0,0,n-1) ;
    }
    
    int sumRange(int left, int right) {
        return querysum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */