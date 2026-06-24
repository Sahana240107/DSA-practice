/*Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 736K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V*/

class Solution {
    bool bfs(int s,vector<int> adj[],vector<bool>& visited)
    {
        queue<pair<int,int>> q;
        q.push({s,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            visited[node]=true;
            for(auto adjNode:adj[node])
            {
                if(!visited[adjNode])
                    q.push({adjNode,node});
                else if(parent!=adjNode)
                    return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int node1=edges[i][0];
            int node2=edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,adj,visited))
                    return true;
            }
        }
        return false;
    }
};


//DFS
class Solution {
    bool dfs(int node,int parent,vector<int> adj[],vector<bool>& visited)
    {
        visited[node]=true;
        for(int adjacent:adj[node])
        {
            if(!visited[adjacent])
            {
                if(dfs(adjacent,node,adj,visited))
                    return true;
            }
            else if(adjacent!=parent)
                return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int node1=edges[i][0];
            int node2=edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};