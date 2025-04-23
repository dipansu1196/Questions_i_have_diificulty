class Solution {
public:
    int result = 0;

    void dfs(TreeNode* node, vector<long long>& path, int targetSum) {
        if (!node) return;

        path.push_back(node->val);

        long long sum = 0;
        // Check all suffixes of the current path ending at this node
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) {
                result++;
            }
        }

        dfs(node->left, path, targetSum);
        dfs(node->right, path, targetSum);

        path.pop_back(); // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> path;
        dfs(root, path, targetSum);
        return result;
    }
};
