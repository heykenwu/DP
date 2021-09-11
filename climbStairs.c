/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

int climbStairs(int n){
    int arr[46] = {0};
    arr[1] = 1;
    arr[2] = 2;
    int count = 3;
    for(;count<=n;count++){
        arr[count] = arr[count-1]+arr[count-2];
    }
    return arr[n];
}