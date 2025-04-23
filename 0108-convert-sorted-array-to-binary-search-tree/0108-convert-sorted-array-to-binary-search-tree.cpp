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
  TreeNode * helper(vector<int>& arr,int l,int h){
    if(l>h) return nullptr;
    int mid= l+(h-l)/2;
    TreeNode* temp =new TreeNode(arr[mid]);
    temp->left=helper(arr,l,mid-1);
    temp->right= helper(arr,mid+1,h);
    return temp;
  }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n=arr.size();
        return helper(arr,0,n-1);
    }
};