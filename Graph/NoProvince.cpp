/*Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
Input:[[1, 0, 1],[0, 1, 0],[1, 0, 1]]
 
Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
*/
// User function Template for C++

class Solution {
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& visited)
    {
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            if(adj[node][i]==1 && !visited[i])
                dfs(i,adj,visited);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int count=0;
        vector<bool> visited(adj.size(),false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
        
    }
};