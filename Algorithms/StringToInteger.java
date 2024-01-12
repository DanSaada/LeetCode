class Solution {
    public int myAtoi(String s) {
         // Ensure the input string is not null
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int length = s.length();
        int index = 0;

        // Skip whitespace characters
        while (index < length && s.charAt(index) == ' ') {
            index++;
        }

        // If we reached the end of string after skipping spaces, return 0
        if (index == length) {
            return 0;
        }

        // Determine the sign based on the current character
        int sign = 1;
        if (s.charAt(index) == '-') {
            sign = -1;
            index++;
        } else if (s.charAt(index) == '+') {
            index++;
        }

        int result = 0;
        // Pre-calculate the threshold to check for overflow
        int threshold = Integer.MAX_VALUE / 10;

        // Convert the number
        while (index < length) {
            char currentChar = s.charAt(index);

            // Break if the current character is not a digit
            if (currentChar < '0' || currentChar > '9') {
                break;
            }

            // Check for overflow when adding a new digit
            if (result > threshold || (result == threshold && currentChar > '7')) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            // Update result with the new digit
            result = result * 10 + (currentChar - '0');
            index++;
        }

        // Apply the determined sign to the result and return
        return sign * result;
    }
}