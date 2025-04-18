class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      vector<int>result;
      for(auto& n:nums){
      mp[n]++;
      } 
      vector<pair<int,int>> vec(mp.begin(),mp.end());
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second; 
    });
     for(auto& it:vec){
        if(k==0){
            break;
        }

        result.push_back(it.first);
        k--;
     }
     return result;
    }
};