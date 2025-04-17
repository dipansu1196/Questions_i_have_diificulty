class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Bubble sort based on the starting point of each interval
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (intervals[j][0] > intervals[j + 1][0]) {
                    swap(intervals[j], intervals[j + 1]);
                }
            }
        }

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= result.back()[1]) { // overlapping
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
