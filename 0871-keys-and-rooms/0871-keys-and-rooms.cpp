class Solution {
public:
void bfs(vector<vector<int>> & rooms,int source,vector<bool> &visited){
    queue<int>q;
    q.push(source);
    visited[source]=true;
  while(!q.empty()){
    int e=q.front();
     q.pop();
     for(int v: rooms[e]){
        if(!visited[v]){
           visited[v]=true;
           q.push(v);
        }
     }
  }
    
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n= rooms.size();
        vector<bool> visited(n,false);
        
        bfs(rooms,0,visited);
        for(bool x: visited){
            if(!x) return false;
        }
        return true;
    }
};