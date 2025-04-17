bool cmp(vector<int>& a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime= intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
            }else{
                lastEndTime=intervals[i][1];
            }
        }
        return ans;
    }
};
// 2nd Approach

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1]; // sort by end time
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int n = intervals.size();
        int firstStartTime = intervals[n - 1][0]; // start time of the last interval

        for (int i = n - 2; i >= 0; i--) {
            if (intervals[i][1] > firstStartTime) {
                // overlap → remove this
                count++;
            } else {
                // no overlap → update
                firstStartTime = intervals[i][0];
            }
        }

        return count;
    }
};
