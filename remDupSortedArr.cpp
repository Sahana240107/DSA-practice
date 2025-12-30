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

//using sorting O(n log n)

vector<int> removeDuplicate(vector<int> a)
{
    sort(a.begin(),a.end());
    vector<int> ans;
    for(int i=0;i<a.size();i++)
    {
        if(i==0 || a[i]!=a[i-1])
            ans.push_back(a[i]);
    }
    return ans;
}

//using unordered_set O(n) space O(n) [does not maintain order]

vector<int> removeDuplicates(vector<int> a)
{
    unordered_set<int> s(a.begin(),a.end());
    return vector<int> ans(s.begin(),s.end());
}

//using unordered_set maintining order

vector<int> removeDuplicates(vector<int> a)
{
    unordered_set<int> s;
    vector<int> ans;
    for(int x:a)
    {
        if(s.find(x)==s.end())
        {
            s.insert(x);
            ans.push_back(x);
        }
    }
    return ans;
}