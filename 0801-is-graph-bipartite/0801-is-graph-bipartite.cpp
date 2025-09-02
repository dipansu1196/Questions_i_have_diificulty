class Solution {
public:
bool BFS(vector<vector<int>>& graph,int i,vector<int>& color,int currColor){
queue<int> que;
que.push(i);

 if (color[i] == -1) color[i] = currColor;
while(!que.empty()){
    int u= que.front();
    que.pop();
    for(auto &v:graph[u] ){
        if(color[v]==color[u] ) return false;
        else if(color[v]==-1){ color[v]=1-color[u];
        que.push(v);}
    }
}
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();

        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!BFS(graph,i,color,1))
                return false;
            }
        }
        return true;
    }
};