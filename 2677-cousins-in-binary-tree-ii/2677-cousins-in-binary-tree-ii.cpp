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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);
        int sum=0;
        vector<int> levelsum;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL){
                sum+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            else{
                levelsum.push_back(sum);
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }

        q.push(root);
        root->val=0;
        int i=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
            TreeNode* curr=q.front();
            q.pop();
            int ssum=curr->left!=NULL ? curr->left->val:0;
            ssum+=curr->right!=NULL ? curr->right->val:0;
            if(curr->left){
                curr->left->val=levelsum[i]-ssum;
                q.push(curr->left);
            }
            if(curr->right){
                curr->right->val=levelsum[i]-ssum;
                q.push(curr->right);
            }
            }
            i++;
        }
        return root;
        
    }
};