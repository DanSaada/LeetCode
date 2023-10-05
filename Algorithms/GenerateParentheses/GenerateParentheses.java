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

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generate(n, n, "", result);
        return result;
    }

    private void generate(int left, int right, String current, List<String> result) {
        if (left == 0 && right == 0) {
            result.add(current);
            return;
        }

        if (left > 0) {
            generate(left - 1, right, current + "(", result);
        }

        if (right > left) {
            generate(left, right - 1, current + ")", result);
        }
    }
}