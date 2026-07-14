/*Minimize Max Distance to Gas Station
Difficulty: HardAccuracy: 38.36%Submissions: 132K+Points: 8Average Time: 40m
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
*/

//Brute Force
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n=stations.size();
        if(n<=1)
            return 0.0;
        vector<int> placed(n-1,0);
        for(int i=0;i<K;i++)
        {
            long double maxLen=-1.0;
            int max_ind=-1;
            for(int j=0;j<n-1;j++)
            {
                long double dif=stations[j+1]-stations[j];
                long double section=dif/(long double)(placed[j]+1.0);
                if(section>maxLen)
                {
                    maxLen=section;
                    max_ind=j;
                }
            }
            placed[max_ind]++;
        }
        long double ans=-1.0;
        for(int i=0;i<n-1;i++)
        {
            long double dif=stations[i+1]-stations[i];
            long double section=dif/(long double)(placed[i]+1.0);
            ans=max(ans,section);
        }
        return ans;
    }
};

//better solution with heap
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n=stations.size();
        if(n<=1)
            return 0.0;
        vector<int> placed(n-1,0);
        priority_queue<pair<long double,int>> pq;
        for(int i=0;i<n-1;i++)
        {
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int i=0;i<K;i++)
        {  
            int ind=pq.top().second;
            pq.pop();
            placed[ind]++;
            long double dif=stations[ind+1]-stations[ind];
            long double newSection=dif/(long double)(placed[ind]+1.0);
            pq.push({newSection,ind});
        }
        return pq.top().first;
    }
};