/*Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.
Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count duplicate elements.
Note: If there is no intersection then return an empty array.

Examples:

Input: arr1[] = [1, 2, 3, 4], arr2[] = [2, 4, 6, 7, 8]
Output: [2, 4]
Explanation: 2 and 4 are only common elements in both the arrays.*/

class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i=0,j=0,n=arr1.size(),m=arr2.size();
        vector<int> ans;
        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j])
            {
                if(ans.empty() || ans.back()!=arr1[i])
                    ans.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i]<arr2[j])
                i++;
            else 
                j++;
        }
        return ans;
    }
};