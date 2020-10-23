/**** Leetcode-Easy 0001# Two Sum *****/

/***
Problems: 

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
***/

/***
■ Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

■ Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

■ Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

<<Constraints>>
■ 2 <= nums.length <= 105
■ -109 <= nums[i] <= 109
■ -109 <= target <= 109
■ Only one valid answer exists.
***/ 

/**
■ Note: The returned array must be malloced, assume caller calls free().
■ map requirs <map> (its is a red-black tree structure)
<<map>> : https://mropengate.blogspot.com/2015/12/cc-map-stl.html
<<hash table>> : https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/
**/
 
//***********************************************************************************//
// Develop in C++ :

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hashmap;
        map<int, int>::iterator iter;
        
        for(int i = 0; i<nums.size(); i++)
        {
            iter = hashmap.find(target - nums[i]);
            
            if(iter != hashmap.end())              // when hashmap find fail => iter == hashmap.end()
            {
                result.push_back(iter->second);    // iter->first : value, iter->second : key
                result.push_back(i);               
                return result;                     // return answer
            }
            else                                   
                hashmap.insert(pair<int, int>(nums[i], i)); // insert format : <value, key>
        }
        return result;
    }
};

/***
■  Runtime : 16 ms
■  Memory : 10.3 MB

■  Time Complexity: O(n). 
■  Space Complexity: O(1).
***/