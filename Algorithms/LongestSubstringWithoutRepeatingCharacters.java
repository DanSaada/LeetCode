class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int[] lastSeen = new int[128]; // Assuming ASCII characters

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            char rightChar = s.charAt(right);
            // if the character was already seen the left pointer will jump one index infront of where it was last seen
            left = Math.max(left, lastSeen[rightChar]);
            maxLength = Math.max(maxLength, right - left + 1);
            lastSeen[rightChar] = right + 1;
        }

        return maxLength;
    }
}
