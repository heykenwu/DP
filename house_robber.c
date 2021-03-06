/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Note: Create an empty array (in this case called sum) to compare the max cost of the previous building sum and current building cost plus the -2 building max sum.
*/
#define max(X,Y) (X>Y?X:Y)

int rob(int* nums, int numsSize){
    int* sum = (int*) malloc(numsSize*sizeof(int));
    int i = 0;
    for(;i<numsSize;i++){
        if(i==0){
            sum[i] = nums[i];
        } else if (i == 1){
            sum[i] = max(nums[i],nums[i-1]);
        } else {
            sum[i] = max(nums[i]+sum[i-2],sum[i-1]);   
        }
    }
    return sum[numsSize-1];
}