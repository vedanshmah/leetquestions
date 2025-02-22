/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    TreeNode* solve(const string& traversal,int &i,int depth){
        if(i>=n){
            return nullptr;
        }
        int j=i;
        while(j<n && traversal[j]=='-'){
            j++;
        }
        int dash=j-i;
        if(dash!=depth){
            return nullptr;
        }
        i=j;
        int num=0;
        while(i<n && isdigit(traversal[i])){
            num=(num*10) + (traversal[i]-'0');
            i++;
        }

        TreeNode* root=new TreeNode(num);
        root->left=solve(traversal,i,depth+1);
        root->right=solve(traversal,i,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.size();
        int depth=0;
        int i=0;
        return solve(traversal,i,depth);
    }
};