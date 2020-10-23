/**** Leetcode-Easy 0009# Palindrome Number *****/

/***
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?
***/

/***
■ Example 1:

Input: x = 121
Output: true

■ Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

■ Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

■ Example 4:

Input: x = -101
Output: false
 

<<Constraints>>

■ -231 <= x <= 231 - 1
***/

//***********************************************************************************//
// Develop in C++ :

class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0 || (x%10 == 0 && x != 0))  // exclusive edge condition
        return false;
    
    int revert = 0;
    while(x>revert)
    {
        revert = revert * 10 + x % 10;
        x /= 10;
    }
    return x == revert || x == revert / 10;
    }
};

/***
■  Runtime : 24 ms
■  Memory : 6.3 MB

■  Time complexity : O(log_{10}(n))We divided the input by 10 for every iteration, so the time complexity is O(log_{10}(n)).
■  Space Complexity: O(1).
***/