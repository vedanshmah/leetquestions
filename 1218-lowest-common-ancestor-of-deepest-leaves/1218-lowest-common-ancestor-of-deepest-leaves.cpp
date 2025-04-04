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
// class Solution {
// public:
//     int maxd=0;
//     void depth(TreeNode* root,unordered_map<int,int> &mp,int d){
//         //base
//         if(!root){
//             return;
//         }
//         //rec
//         maxd=max(maxd,d);
//         mp[root->val]=d;
//         depth(root->left,mp,d+1);
//         depth(root->right,mp,d+1);
//     }
//     TreeNode* lca(TreeNode* root,unordered_map<int,int> mp){
//         //base
//         if(root==NULL || mp[root->val]==maxd){
//             return root;
//         }
//         //rec
//         TreeNode* l=lca(root->left,mp);
//         TreeNode* r=lca(root->right,mp);
//         if(l && r){
//             return root;
//         }
//         if(l!=nullptr){
//             return l;
//         }
//         return r;
//     }
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         unordered_map<int,int> mp;
//         depth(root,mp,0);
//         return lca(root,mp);
//     }
// };
class Solution {
public:
    unordered_map<int, int> mp;
    int maxD = 0;

    TreeNode* LCA(TreeNode* root) {
        if(root == NULL || mp[root->val] == maxD) {
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l && r) {
            return root;
        }

        return l != NULL ? l : r;
    }

    void depth(TreeNode* root, int d) {
        if(!root) {
            return;
        }

        maxD = max(maxD, d);
        mp[root->val] = d;
        depth(root->left, d+1);
        depth(root->right, d+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);

        return LCA(root);
    }
};