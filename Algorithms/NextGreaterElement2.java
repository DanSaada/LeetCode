class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);

        Stack<Integer> stack = new Stack<>();
        //We traverse the array twice to handle the circular nature of the array. 
        for (int i = 0; i < 2 * n; i++) {
             //We use modulo for to stay within the bounds of the original array.
            int num = nums[i % n];

            //While the stack is not empty and the current element (num) is greater
            //than the element at the top of the stack
            while (!stack.isEmpty() && nums[stack.peek()] < num) {
                // update the result for the element at the top of the stack and pop
                // the stack.
                result[stack.pop()] = num;
            }

            //If we are still within the bounds of the original array
            if (i < n) {
                stack.push(i);
            }
        }

        return result;
    }
}