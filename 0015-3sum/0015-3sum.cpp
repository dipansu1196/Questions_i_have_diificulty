class Solution {
public:
    void twosum(vector<int>& nums, int k, vector<vector<int>>& ans, int target) {
        int i = k;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                ans.push_back({-target, nums[i], nums[j]});
                // Skip duplicates for i
                while (i < j && nums[i] == nums[i + 1]) i++;
                // Skip duplicates for j
                while (i < j && nums[j] == nums[j - 1]) j--;
                // Move to the next potential pair
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            twosum(nums,i+1,ans,-nums[i]);
        }
        return ans;
    }
};