/*4. Median of Two Sorted Arrays
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int cnt=0;
        int element1=-1,element2=-1;
        int ind1=(n+m)/2,ind2=(n+m)/2-1;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                if(cnt==ind1)
                    element1=nums1[i];
                if(cnt==ind2)
                    element2=nums1[i];
                i++;
            }
            else
            {
                if(cnt==ind1)
                    element1=nums2[j];
                if(cnt==ind2)
                    element2=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<n)
        {
            if(cnt==ind1)
                element1=nums1[i];
            if(cnt==ind2)
                element2=nums1[i];
            i++;
            cnt++;
        }
        while(j<m)
        {
            if(cnt==ind1)
                element1=nums2[j];
            if(cnt==ind2)
                element2=nums2[j];
            j++;
            cnt++;
        }
        if((n+m)%2==0)
        {
            return (element1+element2)/2.0;
        }
        return element1;
    }
};

//Optimal BS
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        int n=n1+n2;
        int low=0,high=n1;
        int left=(n+1)/2;
        while(low<=high)
        {
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) 
                r1=nums1[mid1];
            if(mid2<n2)
                r2=nums2[mid2];
            if(mid1-1>=0)
                l1=nums1[mid1-1];
            if(mid2-1>=0)
                l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1)
            {
                if(n%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high=mid1-1;
            else
                low=mid1+1;
        }
        return -1;
    }
};