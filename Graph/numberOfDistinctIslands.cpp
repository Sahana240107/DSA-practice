/*Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 134K+Points: 4Average Time: 20m
Given a grid of size n × m, consisting of characters 'L' and 'W', where 'L' represents Land and 'W' represents Water, find the number of distinct islands in the grid.

An island is a group of one or more connected land cells. Two land cells are considered connected if they are adjacent horizontally or vertically (4-directional connectivity).

Two islands are considered distinct if their shapes are different.
If two shapes become same after rotation, then they are considered different.  In the second example below, the two corner L shaps are considered different.
Examples :

Input: n = 4, m = 5
 
Output: 1
Explanation: The grid contains two islands. Both islands have the same shape (a 2 × 2 block of land), so they are counted as a single distinct island.

Input: n = 4, m = 5
 
Output: 3
Explanation: There are four islands in the grid. Two islands have the same shape, while the other two have different shapes. Therefore, the number of distinct island shapes is 3.

*/