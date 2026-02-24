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
    int bintoint(int n){
        int ans=0;
        int pwr=0;
        while(n){
            int rem=n%10;
            ans+=rem*(1<<pwr);
            pwr++;
            n/=10;
        }
        return ans;
    }
    void helper(TreeNode* root,int &ans,int bin){
        //base
        if(!root){
            return;
        }
        bin=(bin<<1) | root->val;
        if(!root->left && !root->right){
            ans+=bin;
            return;
        }
        //rec
        helper(root->left,ans,bin);
        helper(root->right,ans,bin);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        helper(root,ans,0);
        return ans;
    }
};