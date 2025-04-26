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
 TreeNode* insert(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
         TreeNode* temp= new TreeNode(val);
         if(root->val> val){  // go left
              if(root->left==NULL){
root->left=temp;
return root;
              }else{
              insert(root->left,val);
              }
         }
         else{
            // go right
            
              if(root->right==NULL){
root->right=temp;
return root;
              }
              else{
                 insert(root->right,val);
              }
         }
         return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root= new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
           insert(root,pre[i]);
        }
        return root;
    }
};