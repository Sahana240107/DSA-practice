/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed.
 Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted,
 you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/

/*Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0,t,j=-1;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==val)
           {
            j=i;//j starts from first index with val
            break;
           }
        }
        if(j==-1){
            return nums.size();
        }
        for(int i=j+1;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                swap(nums[i],nums[j]);//moving val to end of array
                j++;
            }
        }
        return j;

    }
};