/**** Leetcode-Easy 0167# Two Sum II - Input array is sorted *****/

/***
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

■ Your returned answers (both index1 and index2) are not zero-based.
■ You may assume that each input would have exactly one solution and you may not use the same element twice.
***/

/***
■ Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

■ Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]

■ Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

<<Constraints>>

■ 2 <= nums.length <= 3 * 104
■ -1000 <= nums[i] <= 1000
■ nums is sorted in increasing order.
■ -1000 <= target <= 1000
***/

//***********************************************************************************//
// Develop in C++ :

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 // !!! This is a two pointer solution. Go through the array by once.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if(numbers.empty()) return result;				// Input NULL condition
        int front = 0, end = numbers.size()-1;
        
        while(front < end){
            int sum = numbers[front] + numbers[end];
            if(sum == target) {
                result.push_back(front+1);
                result.push_back(end+1);
                return  result;
            }
            else if(sum < target) 
                front++;
            else 
                end--;
        }
        return result;
    }
};

/***
■  Runtime : 8 ms
■  Memory : 9.8 MB

■  Time complexity : O(n)
■  Space Complexity: O(1).
***/