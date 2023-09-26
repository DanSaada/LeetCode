/*
Given an integer array nums, design an algorithm to randomly shuffle the array. 
All permutations of the array should be equally likely as a result of the shuffling.
Implement the Solution class:
Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 
Example 1:
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

Constraints:
1 <= nums.length <= 50
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 104 calls in total will be made to reset and shuffle.*/


#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int numsSize;
    int* originalNums;
    int* shuffledNums;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* solution = (Solution*)malloc(sizeof(Solution));
    solution->originalNums = (int*)malloc(sizeof(int) * numsSize);
    solution->shuffledNums= (int*)malloc(sizeof(int) * numsSize);
    solution->numsSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        solution->originalNums[i] = nums[i];
    }
    return solution;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->numsSize;
    return obj->originalNums;
}

void swap(int* x, int* y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void fisherYatesShuffle(int* array, int size) {
    for (int i = size - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        if (array[i] != array[j]){
            swap(&array[i], &array[j]);
        }
    }
}

int* solutionShuffle(Solution* obj, int* retSize) {
    for (int i = 0; i < obj->numsSize; i++){
        obj->shuffledNums[i] = obj->originalNums[i];
    }

    fisherYatesShuffle(obj->shuffledNums, obj->numsSize);
    *retSize = obj->numsSize;
    return obj->shuffledNums;
}

void solutionFree(Solution* obj) {
    free(obj->shuffledNums);
    free(obj->originalNums);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/