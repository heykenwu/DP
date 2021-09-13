/*
Jump Game 2
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

Note: 

There is three main variables:

1.max_index: to store the current max index you can go in the array.

2.end: The max index you can go from the last jump.

3.count: To count the jump.

The way to solve this question is to loop through the array,
update the maximum index in the current looped index if it is larger than the max index it can go from the last looped index,
since you have to jump in the first index, you need to update the end variable to the max_index once it go to the the index it can go at best. (Also count++)
return the number of the count number

*/
#define max(X,Y) (X>Y?X:Y)

int jump(int* nums, int numsSize){
    if((numsSize == 1)){
        return 0;
    }
    int max_index = 0, i = 0, end = 0, count = 0;
    for(;i < numsSize - 1 && (end < numsSize - 1); i++){    
        max_index = max((nums[i]+i),max_index);
        if(i == end) {
            end = max_index;
            count++;
        }
    }
    return count;
}