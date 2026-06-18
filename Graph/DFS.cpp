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

//USING STACK
vector<int> dfs(vector<vector<int>>& adj)
{
    vector<int> ans;
    int V=adj.size();
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            st.push(i);
            while(!st.empty())
            {
                int node=st.top();
                st.pop();
                if(!visited[node])
                    ans.push_back(node);
                for(int j=adj[node].size();j>=0;j--)
                {
                    int neighbour=adj[node][j];
                    if(!visited[neighbour])
                        st.push(neighbour);
                }
            }
        }
    }
    return ans;
}