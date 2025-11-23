/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true*/

//Brute force
lass Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

//optimized

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums) {
            if(seen.find(num) != seen.end())  // already exists
                return true;
            seen.insert(num);
        }
        return false;
    }
};



