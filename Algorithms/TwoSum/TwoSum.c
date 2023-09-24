/*Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.


Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    // Create an array of pairs to store the original values and their indices.
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].val = nums[i];
        pairs[i].index = i;
    }

    // Sort the pairs array based on values.
    qsort(pairs, numsSize, sizeof(Pair), compare);

    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = pairs[left].val + pairs[right].val;
        if (sum == target) {
            result[0] = pairs[left].index;
            result[1] = pairs[right].index;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    free(pairs);
    return result;
}
