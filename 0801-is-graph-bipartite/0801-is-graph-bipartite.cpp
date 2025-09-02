class Solution {
public:
    bool dfsCheck(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor;

        for (int v : graph[curr]) {
            if (color[v] == color[curr]) return false; // same color as parent → not bipartite
            
            if (color[v] == -1) {
                if (!dfsCheck(graph, v, color, 1 - currColor)) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  // -1 = uncolored, 0/1 are two colors

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfsCheck(graph, i, color, 0)) return false;
            }
        }
        return true;
    }
};
