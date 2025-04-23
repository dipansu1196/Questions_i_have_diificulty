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
vector<vector<int>> result;
void fill(TreeNode* root,int sum,vector<int> tmp,int &targetSum){
    if(!root){
        return;
    }
    sum+=root->val;
    tmp.push_back(root->val);
    if(root->left==NULL&& root->right==NULL){
        if(sum==targetSum){
            result.push_back(tmp);
        }
        return;
    }
    fill(root->left,sum,tmp,targetSum);
    fill(root->right,sum,tmp,targetSum);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> tmp;
        fill(root,sum,tmp,targetSum);
        return result;
    }
};