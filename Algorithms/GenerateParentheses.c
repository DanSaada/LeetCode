/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generate(int l, int r, int index, int* returnSize, char* str, char** result) {
    if (l == 0 && r == 0){
        result[*returnSize] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(result[*returnSize], str);
        (*returnSize)++;
        return;
    }
    if (l) {
        str[index] = '(';
        generate(l-1, r, index+1, returnSize, str, result);
    }

    if (r > l) {
        str[index] = ')';
        generate(l, r-1, index+1, returnSize, str, result);
    }
}


char** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    char** result = (char**)malloc(sizeof(char*) * (2 << (2 * n - 1)));
    char* str = (char*)malloc(sizeof(char) * (2 * n + 1));
    str[2 * n] = '\0';
    
    generate(n, n, 0, returnSize, str, result);
    free(str);
    return result;
}