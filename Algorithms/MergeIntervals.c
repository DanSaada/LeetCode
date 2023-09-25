/*Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    // sort the intervals by their intervals[0]
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // create a stack result return variable
    int** stack = (int**)malloc(sizeof(int*)*intervalsSize);
    stack[0] = intervals[0];
     int stackSize = 1;

    for (int i = 1; i < intervalsSize; i++) {
        int currentStackRight = stack[stackSize-1][1];
        int currentIntervalsRight = intervals[i][1];

        // if 2 intervals overlaps
        if(intervals[i][0] <= currentStackRight){
           stack[stackSize -1][1] = currentIntervalsRight > currentStackRight ? currentIntervalsRight : currentStackRight;
        }else{ // just pass the interval to the solution as is and increament the stack size fofr to open a new interval
            stack[stackSize++] = intervals[i];
        }
    }

    *returnSize = stackSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return stack;
}

