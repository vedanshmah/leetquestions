class Solution {
public:
     void solve(int row,int n, vector<bool> &colo, vector<bool> &ldiag, vector<bool> &rdiag,vector<vector<string>> &res, vector<string> &sol ){
        for(int col=0;col<n;col++){
            if(row==n){
                res.push_back(sol);
                return;
            }

            if(!colo[col] && !ldiag[(row-col)+n-1] && !rdiag[row+col]){
                sol[row][col]='Q';
                colo[col]=true;
                ldiag[(row-col)+n-1]=true;
                rdiag[row+col]=true;

                solve(row+1,n,colo,ldiag,rdiag,res,sol);
                sol[row][col]='.';

                colo[col]=false;
                ldiag[(row-col)+n-1]=false;
                rdiag[row+col]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> colo(n,false);
        vector<bool> ldiag(n+n-1,false);
        vector<bool> rdiag(n+n-1,false);
        vector<vector<string>> res;
        vector<string> sol(n,string(n,'.'));
        solve(0,n,colo,ldiag,rdiag,res,sol);
        return res;
    }
};