/*Given coordinates of four points in a plane. Find if the four points form a square or not.

Example 1:

Input:
points=(0,0),(0,1),(1,0),(1,1)
Output:
1
Explanation:
These points form a square.
Example 2:

Input:
points=(0,0),(1,1),(1,0),(0,2)
Output:
0
Explanation:
These four points do not form a square.
*/

// User function Template for C++

class Solution {
  public:
    int fourPointSquare(vector<vector<int>> points) {
        // code here
        vector<int> dist;
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                dist.push_back(dx*dx+dy*dy);
            }
        }
        sort(dist.begin(),dist.end());
        if(dist[0]==dist[1]&&dist[1]==dist[2]&&dist[2]==dist[3]&&dist[4]==dist[5]&&dist[4]==2*dist[0]&&dist[0]!=0)
            return 1;
        return 0;
    }
};