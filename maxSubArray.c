/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105

Note: Two vaiable uses in this case:

1. max_sum: store the best max contiguous sum

2. conti: store the current max contiguous sum

The way to solve this problem is to loop every element through the array.
Compare the current contigous sum plus the value of the current index number and the value of the current index number itself.
If the current value itself is bigger than the current max contiguous sum, it will replace the contiguous to its value (means that the contiguous will break and 
start again from the current index).
Finally, compare the best max contiguous sum and the current max contiguous sum to know if the current contiguous sum is larger than best max contiguous sum.
If yes, replace the value.
*/

#define max(X,Y) (X>Y?X:Y)

int maxSubArray(int* nums, int numsSize){
    int max_sum = nums[0],conti = nums[0]; 
    for(int i = 1; i < numsSize; i++){
            conti = max(nums[i]+conti, nums[i]);
            max_sum = max(conti, max_sum);
    }
    return max_sum;
}