/*Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], 
where each adj[i] represents the list of vertices connected to vertex i. 
Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, 
and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.*/
class Solution {
    void dfshelp(int node,vector<vector<int>>& adj,vector<bool>& visited,vector<int>& result)
    {
        visited[node]=true;
        result.push_back(node);
        for(int i:adj[node])
        {
            if(!visited[i])
                dfshelp(i,adj,visited,result);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(),false);
        vector<int> ans;
        dfshelp(0,adj,visited,ans);
        return ans;
    }
};