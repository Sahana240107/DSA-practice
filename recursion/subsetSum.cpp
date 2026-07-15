/*Subset Sum : Sum of all Subsets

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order*/

class Solution {
public:
    void findSums(int ind, int sum, vector<int>& arr, vector<int>& sums) {
        if (ind == arr.size()) {
            sums.push_back(sum);
            return;
        }

        // Include current element
        findSums(ind + 1, sum + arr[index], arr, sums);

        // Exclude current element
        findSums(ind + 1, sum, arr, sums);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        findSums(0, 0, arr, sums);
        sort(sums.begin(), sums.end()); 
        return sums;
    }
};
