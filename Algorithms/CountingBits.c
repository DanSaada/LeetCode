/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
Constraints:
0 <= n <= 105*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * (n + 1));
    arr[0] = 0;

    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i >> 1] + (i & 1);
    }

    *returnSize = n + 1;
    return arr;
}

//0001
//0010
//0011
//0100