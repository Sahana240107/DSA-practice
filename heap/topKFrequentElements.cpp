/*347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]*/

class Solution {
    struct compare
    {
        bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            return a.second>b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto it:mp)
        {
            pq.push(it);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};