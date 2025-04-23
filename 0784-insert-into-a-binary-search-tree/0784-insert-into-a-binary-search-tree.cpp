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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
         TreeNode* temp= new TreeNode(val);
         if(root->val> val){  // go left
              if(root->left==NULL){
root->left=temp;
return root;
              }else{
              insertIntoBST(root->left,val);
              }
         }
         else{
            // go right
             // go left
              if(root->right==NULL){
root->right=temp;
return root;
              }
              else{
                 insertIntoBST(root->right,val);
              }
         }
         return root;
    }
};