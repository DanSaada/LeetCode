class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] lis = new int[nums.length];
        int maxSize = 0; // longest subsequence

        for (int num : nums) {
            int start = 0, end = maxSize;

            while (start != end) { // Binary Search
                int mid = (start + end) / 2;
                if (lis[mid] < num) start = mid + 1;
                else end = mid;
            }

            // Note: If num is smaller than the last element in lis, 
            //       we update the last element in lis to be num.
            //       Otherwise, num is larger, so we add it to lis 
            //       to be the new last element.
            lis[start] = num;
            maxSize = (start == maxSize) ? maxSize + 1 : maxSize;
        }

        return maxSize;
    }
}

