class Solution {
public:
    bool solve(vector<int>& arr, int start,vector<bool> &visited){
        //base
        if(arr[start]==0) return true;
        if(visited[start]) return false;
        //rec
        visited[start]=true;
        bool right=false;
        bool left=false;
        if(start+arr[start] < arr.size()){
            right=solve(arr,start+arr[start],visited);
        }
        if(start-arr[start] >= 0){
            left=solve(arr,start-arr[start],visited);
        }
        if(right || left) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(),false);
        return solve(arr,start,visited);
    }
};

