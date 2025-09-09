class Solution {
public:
typedef pair<int,int> P;

int prim(vector<vector<P>> & adj,int n){
    priority_queue<P,vector<P>,greater<P>> pq;
    int sum=0;
    vector<bool>inMST(n,false);
    pq.push({0,0});

    while(!pq.empty()){
        auto el= pq.top();
         pq.pop();
        int wt= el.first;
        int node= el.second;
     
        if(inMST[node]) continue;
        inMST[node]=true;
        sum+=wt;
        for(auto &e: adj[node]){
            int neighbour= e.first;
            int neighbour_wt=e.second;
            if(!inMST[neighbour]){
               
                pq.push({neighbour_wt,neighbour});
            }
        }
    }
    return sum;
}

    int minCostConnectPoints(vector<vector<int>>& points) {
        
 
  int n=points.size();
   vector<vector<P>> adj(n);

  for(int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
        int x1= points[i][0];
        int y1= points[i][1];

        int x2=points[j][0];
        int y2=points[j][1];

        int d= abs(x2-x1)+abs(y2-y1);
        adj[i].push_back({j,d});
        adj[j].push_back({i,d});
    }
  }
return prim(adj,n);
    }
};