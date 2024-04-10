class Solution {
    public boolean isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sumOfSquares(slow); // Move slow pointer one step
            fast = sumOfSquares(sumOfSquares(fast)); // Move fast pointer two steps
        } while (slow != fast); // Loop until the pointers meet

        return slow == 1; // If slow equals 1, then we found a cycle that includes 1, so it's a happy number
    }

    private int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
}