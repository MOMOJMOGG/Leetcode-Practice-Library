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
■ abs requirs <stdlib.h>
**/
 
//***********************************************************************************//
// Develop in C :

// 1. build hash table function (insert, search, free)
struct hashnode{
    int value;              // hashtable : value
    int index;              // hashtable : key
    struct hashnode* next;  // link list
};

void insert(struct hashnode** hashtable, int value, int index, int numSize)
{
    int tempindex = abs(value) % numSize;
    struct hashnode *tempnode = hashtable[tempindex];
    struct hashnode *addnode = (struct hashnode*)malloc(sizeof(struct hashnode));
    addnode->value = value;
    addnode->index = index;
    addnode->next = tempnode->next;
    tempnode->next = addnode;
}

int search(struct hashnode** hashtable, int target, int numSize)
{
    int tempindex = abs(target) % numSize;
    struct hashnode* tempnode = hashtable[tempindex]->next;
    while(tempnode)
    {
        if(tempnode->value == target)
            return tempnode->index;                // search succeed : return key
        tempnode = tempnode->next;
    }
    return -1;                                     // search fail : return -1
}

void freeHashTable(struct hashnode** hashtable, int numSize)
{
    int i = 0;
    struct hashnode *tempnode = NULL, *deltarget = NULL;
    for(i = 0; i < numSize; i++)
    {
        tempnode = hashtable[i];
        deltarget = tempnode;
        while(tempnode)
        {
            deltarget = tempnode;
            tempnode = tempnode->next;
            free(deltarget);                    // free pointer memory
        }
    }
    free(hashtable);                            // free pointer memory
}

// 2. twoSum algorithm 
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    int index = 0;
    int* result = NULL;
    *returnSize = 2;             // Leetcode requirs "output sizes" setting avoiding output error.
	
	/*
		malloc : ask for memory without value initialization.
		calloc : ask for memory with value initialization setting as 0.
	*/
	
    struct hashnode** hashtable = (struct hashnode**)malloc(numsSize * sizeof(struct hashnode*));
    
    for(i = 0 ; i< numsSize ; i++)
    {
        hashtable[i] = (struct hashnode*)calloc(1, sizeof(struct hashnode));
    }
    
    for(i = 0 ; i< numsSize ; i++)
    {
        index = search(hashtable, target - nums[i], numsSize);
        if(index == -1)                                // can't find the answer in hashtable
            insert(hashtable, nums[i], i, numsSize);   // insert hashtable <value, key>
        else                                           // find the answer in hashtable
        {                                              // return result and free pointer
            result = (int *)malloc(sizeof(int)*2);
            result[0] = index;
            result[1] = i;
            freeHashTable(hashtable, numsSize);
            return result;
        }
    }
    freeHashTable(hashtable, numsSize);
    return result;
}