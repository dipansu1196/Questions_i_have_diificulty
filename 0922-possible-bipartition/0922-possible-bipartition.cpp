class Solution {
public:
bool checkbfs(auto & adj,int source,vector<int> & color){
    queue<int>q;
    q.push(source);
    color[source]=0;
    while(!q.empty()){
        int u= q.front();
        q.pop();
        for(auto & v:adj[u]){
            if(color[v]==color[u]) return false;
            if(color[v]==-1){
                q.push(v);
                color[v]=1-color[u];
            }
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto & e: dislikes){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        for(int i=0;i<=n;i++){
            if(color[i]==-1){
              if(  !checkbfs(adj,i,color)) return false;
            }
        }
        return true;
    }
};