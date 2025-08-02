/*Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.*/
/*Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.*/
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size(),m=b.size(),i=0,j=0;
        vector<int>Union;
        while(i<n && j<m)
        {
            if(a[i]<=b[j])
            {
                if(Union.size()==0 || Union.back()!=a[i])
                {
                    Union.push_back(a[i]);
                }
                i++;
            }
            else{
                if(Union.size()==0 || Union.back()!=b[j])
                {
                    Union.push_back(b[j]);
                }
                j++;
            }
        }
        while(i<n)
        {
            if(Union.size()==0 || Union.back()!=a[i])
            {
                Union.push_back(a[i]);
            }
            i++;
        }
        while(j<m)
        {
            if(Union.size()==0 || Union.back()!=b[j])
            {
                Union.push_back(b[j]);
            }
            j++;
        }
        return Union;
    }
};