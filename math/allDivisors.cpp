/*Print all Divisors of a given Number
Problem Statement: Given an integer N, return all divisors of N.
A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N*/

class Solution {
public:
    // Function to get all divisors
    vector<int> getDivisors(int N) {
        vector<int> res;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                res.push_back(i);
                if (i != N / i) {
                    res.push_back(N / i);
                }
            }
        }
        return res;
    }
};
