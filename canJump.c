/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

Note: 

set a variable to store the max index you can go to.

loop the array except the last one since the last one is the destination and the loop will also end once the max index variable are larger than the array size (means that it arrived
to the destination).

max_index is to store the maximum index you can go through.

During the for loop, if the max_index is smaller or equal to the current index, return false (because it ends up to the current index and cannot go forward).

after the loop, return true.
*/
bool canJump(int* nums, int numsSize){
    int max_index = 0, i = 0;
    for(;i < numsSize - 1 && max_index < numsSize; i++){
        max_index = ((i+nums[i]) > max_index)? (i+nums[i]):max_index;
        if(max_index <= i) return false;
    }
    return true;
}