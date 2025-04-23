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
long long maxTree(TreeNode* root){
    if(root==NULL) return LLONG_MIN;
    return max((long long)(root->val),max(maxTree(root->right),maxTree(root->left)));

}
long long minTree(TreeNode* root){
    if(root==NULL) return LLONG_MAX;
    return min((long long)(root->val),min(minTree(root->right),minTree(root->left)));

}
    bool isValidBST(TreeNode* root) {
        if(root==NULL||(root->right==NULL&&root->left==NULL)) return true;
        if((long long)(root->val)<= maxTree(root->left)|| (long long)(root->val)>= minTree(root->right)) return false;
    return isValidBST(root->left ) && isValidBST(root->right);
    }
};