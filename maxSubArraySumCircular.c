/*

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: nums = [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: nums = [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: nums = [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

Note:

The key concept to solve this problem is using the kadane algorithm to find the maximum subarray sum and minimum subarray sum.

First, find the sum of all the nums in the array.

Next, find the maximum subarray sum.

And then, find the minimum subarray sum and substract it by the sum of all nums in the array to find the circular maxsubarray. (in this case is add because we flip all the nums in the array)

if the sum in the above step is 0, return the maximum subarray.

otherwise, return the comparison of the circular max subarray and the maximum subarray.

When the linear is bigger than circular max subarray?

The only case that this will happen is the maximum loss is happen in the middle of the array. 

The circlar array algorithm is assume that the last part of the array is connected to the beginning of the array which the only part it ignore is the middle part.
*/
#define max(X,Y) (X>Y?X:Y)
int k(int* nums, int numsSize) {
    int max_number = nums[0], conti = nums[0];
    for(int i = 1; i < numsSize; i++) {
        conti = max(conti + nums[i], nums[i]);
        max_number = max(max_number, conti);
    }
    return max_number;
}
int maxSubarraySumCircular(int* nums, int numsSize){
    int linear = k(nums, numsSize);
    
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum+=nums[i];
        nums[i] *= -1;
    }
    
    int reverse = k(nums, numsSize);
    
    int k1 = sum + reverse;
    
    if(k1 == 0) return linear;
    
    return max(linear, k1);
}