class Solution {
public:

vector<int> topologicalsort(unordered_map<int,vector<int>> &adj,int n, vector<int> &indegree){
    vector<int> result;
    int count=0;
    queue<int> que;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            result.push_back(i);
            count++;
            que.push(i);
        }
    }
    while(!que.empty()){
        int u= que.front();
        que.pop();

        for( int & v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                count++;
                result.push_back(v);
                que.push(v);
            }
        }
    }
    return (result.size() == n) ? result : vector<int>{};
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;

        for( auto& vec:prerequisites){
           int a = vec[0];
           int b= vec[1];
           //{a,b}
           //b---->a
           adj[b].push_back(a);

           indegree[a]++;
        }
        return topologicalsort(adj,numCourses,indegree);
    }
};