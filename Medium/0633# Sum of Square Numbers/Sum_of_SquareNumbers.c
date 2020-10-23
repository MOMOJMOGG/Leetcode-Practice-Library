/**** Leetcode-Medium 0633# Sum of Square Numbers *****/

/***
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
***/

/***
■ Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

■ Example 2:

Input: c = 3
Output: false

■ Example 3:

Input: c = 4
Output: true

■ Example 4:

Input: c = 2
Output: true

■ Example 5:

Input: c = 1
Output: true

<<Constraints>>

■ 0 <= c <= 231 - 1
***/

//***********************************************************************************//
// Develop in C :

//!!! This is a two pointer solution. Go through the string by once.Sqrt to find the answer more efficiency.

bool judgeSquareSum(int c){
    long front = 0, end = sqrt(c);             // use long invoiding overflow of int.
    while(front <= end){
        long pow_sum = front*front + end*end;
        if(pow_sum == c)
            return true;
        else if (pow_sum > c)
            end--;
        else
            front++;
    }
    return false;
}

/***
■  Runtime : 0 ms
■  Memory : 5.7 MB

■  Time complexity : O(sqrt(n))
■  Space Complexity: O(1).
***/