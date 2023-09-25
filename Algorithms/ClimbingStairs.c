/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:
1 <= n <= 45*/

/*
 __________________________________________
|   |   |   |   |   |   |             |   |
| 1 | 1 | 2 | 3 | 5 | 8 | ........... | n |
|___|___|___|___|___|___|_____________|___|

  0   1   2   3   4   5                 n
*/

int climbStairs(int n){
    int countPaths[n+1];
    countPaths[0] = 1;
    countPaths[1] = 1;

    for (int i = 2; i <= n; i++) {
        countPaths[i] = countPaths[i-1] + countPaths[i-2];
    }
    
   return countPaths[n];
    
}