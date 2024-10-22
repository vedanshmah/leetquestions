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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        long long ans=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL){
                ans+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            else{
                if(pq.size()<k){
                    pq.push(ans);
                }
                else if(ans>pq.top()){
                    pq.pop();
                    pq.push(ans);
                }
                if(!q.empty()){
                    q.push(NULL);
                }
                ans=0;
            }
        }
        if(pq.size()<k){
            return -1;
        }
        
        return pq.top();
    }
};