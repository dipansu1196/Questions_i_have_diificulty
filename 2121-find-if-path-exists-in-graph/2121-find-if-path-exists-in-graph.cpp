class Solution {
public:
bool check(auto &mp, int source,int destination,auto & visited){
    if(source==destination ) return true;

    if(visited[source]) return false;
    visited[source]=true;
    for(auto &node: mp[source]){
       if(check(mp,node,destination,visited)) return true;
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> mp;
        vector<bool>visited(n,false);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return check(mp,source,destination,visited);
    }
};