/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].

Note: Compare the previous two steps (1 or 2) and add the cost of the current step.
*/
#define min(X,Y) (X<Y?X:Y)
int minCostClimbingStairs(int* cost, int costSize){
    int* sum = (int*)malloc(costSize*sizeof(int));
    sum[0] = cost[0];
    sum[1] = cost[1];
    int i = 2;
    for(;i<costSize;i++){
        sum[i] = min(sum[i-1],sum[i-2]) + cost[i];
    }
    return min(sum[i-1],sum[i-2]);
}