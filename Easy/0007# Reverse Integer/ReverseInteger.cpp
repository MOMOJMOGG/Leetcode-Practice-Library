/**** Leetcode-Easy 0007# Reverse Integer *****/

/***
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
***/
 
/***
■ Example 1:

Input: x = 123
Output: 321

■ Example 2:

Input: x = -123
Output: -321

■ Example 3:

Input: x = 120
Output: 21

■ Example 4:

Input: x = 0
Output: 0
 

<<Constraints>>

■ -231 <= x <= 231 - 1
***/

//***********************************************************************************//
// Develop in C++ :

class Solution {
public:
    int reverse(int x) {       // int limitation upper bound is  2147483647
    int result = 0;            // int limitation lower bound is  -2147483647 - 1
    while(x!=0)
    {
        int pop = x % 10;
        x /= 10;
        if(result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)) return 0;
        if(result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)) return 0;
        result = result * 10 + pop;
    }
    return result;
    }
};

/***
■  Runtime : 4 ms
■  Memory : 6.1 MB

■  Time Complexity: O(log(x)). There are roughly log_{10}(x) digits in x.
■  Space Complexity: O(1).
***/