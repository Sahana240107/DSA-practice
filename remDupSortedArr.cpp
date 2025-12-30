/*Given an array arr of integers which may or may not contain duplicate elements. Your task is to remove duplicate elements.

Examples:

Input: arr[] = [1, 2, 3, 1, 4, 2]
Output: [1, 2, 3, 4]
Explanation: 2 and 1 have more than 1 occurence. from unsorted arry*/

//Naive approach O(n2)
vector<int> removeDuplicates(vector<int> a)
{
    vector<int> ans;
    for(int i=0;i<a.size();i++)
    {
        bool duplicate=false;
        for(int j=0;j<ans.size();j++)
        {
            if(a[i]==ans[j])
            {
                duplicate=true;
                break;
            }
        }
        if(!duplicate)
            ans.push_back(a[i]);
    }
    return ans;
}

