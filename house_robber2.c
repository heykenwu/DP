/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

Note: loop twice

first loop starts from the first building and then ends at the second last building to prevent the first and the last one
are in the same path.

Second loop starts from the second building and then ends at the last building.


*/
#define max(X,Y) (X>Y?X:Y)

int rob(int* nums, int numsSize){
    if( numsSize == 1) {
        return nums[0];
    }
    int i = 0;
    int* sum = (int*)malloc(numsSize*sizeof(int));
    for(;i<numsSize-1;i++){
        if(i==0){
            sum[i] = nums[i];
        } else if (i == 1) {
            sum[i] = max(nums[i],nums[i-1]);
        } else {
            sum[i] = max(nums[i]+sum[i-2],sum[i-1]);   
        }
    }
    int first = sum[numsSize-2];
    i = 1;
    for(;i<numsSize;i++){
        if(i==1){
            sum[i] = nums[i];
        } else if (i == 2){
            sum[i] = max(nums[i],nums[i-1]);
        } else {
            sum[i] = max(nums[i]+sum[i-2],sum[i-1]);   
        }
    }
    return max(sum[numsSize-1],first);
}