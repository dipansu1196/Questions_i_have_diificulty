class Solution {
public:

void dfs(auto & graph, int node,int target, vector<vector<int>> & result,vector<int> & temp){
temp.push_back(node);
if(node==target) result.push_back(temp);
else{
    for(int &v: graph[node]){
   dfs(graph,v,target,result,temp);
    }
}
temp.pop_back();

}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        int target=n-1;
        vector<int> temp;
        vector<vector<int>> result;
        dfs(graph,0,target,result,temp);
        return result;
    }
};