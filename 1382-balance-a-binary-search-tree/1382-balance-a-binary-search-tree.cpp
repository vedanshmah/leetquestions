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
    vector<int> vec;
    void inorder(TreeNode* root){
        //base
        if(!root){
            return;
        }
        //rec
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);

    }
    TreeNode* buildbst(int l,int r){
        //base
        if(l>r){
            return nullptr;
        }
        //rec
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(vec[mid]);
        root->left=buildbst(l,mid-1);
        root->right=buildbst(mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildbst(0,vec.size()-1);
    }
};