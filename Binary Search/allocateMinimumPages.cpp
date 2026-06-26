/*Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 408K+Points: 4Average Time: 35m
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
*/

class Solution {
    int maxElement(vector<int>& a)
    {
        int maxi=a[0];
        for(int i=1;i<a.size();i++)
        {
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
    int sumArr(vector<int>& a)
    {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        return sum;
    }
    int countStudents(int maxi,vector<int>& a)
    {
        int students=1,pages=0;
        for(int i=0;i<a.size();i++)
        {
            if(pages+a[i]<=maxi)
                pages+=a[i];
            else
            {
                students++;
                pages=a[i];
            }
        }
        return students;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k)
            return -1;
        int low=maxElement(arr);
        int high=sumArr(arr);
        for(int i=low;i<=high;i++)
        {
            if(countStudents(i,arr)==k)
                return i;
        }
        return -1;
    }
};

//OPTIMIZED BINARY SEARCH
class Solution {
    int maxElement(vector<int>& a)
    {
        int maxi=a[0];
        for(int i=1;i<a.size();i++)
        {
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
    int sumArr(vector<int>& a)
    {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        return sum;
    }
    int countStudents(int maxi,vector<int>& a)
    {
        int students=1,pages=0;
        for(int i=0;i<a.size();i++)
        {
            if(pages+a[i]<=maxi)
                pages+=a[i];
            else
            {
                students++;
                pages=a[i];
            }
        }
        return students;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k)
            return -1;
        int low=maxElement(arr);
        int high=sumArr(arr);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(countStudents(mid,arr)<=k)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};