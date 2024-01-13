class Solution {
    public void reverseString(char[] s) {
         if (s == null || s.length <= 1) {
            return; // If the string is empty or has length 1, no need to reverse
        }
        int start = 0, end = s.length - 1;

        while (start < end) {
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            start++;
            end--;
        }

    }
}