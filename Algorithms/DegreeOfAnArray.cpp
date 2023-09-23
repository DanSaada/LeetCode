/*Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 
Example 1:
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 

Constraints:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> counts;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            counts[nums[i]].push_back(i);
        }

        int maxFreq = 0;
        int subLen = numsSize;

        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (it->second.size() > maxFreq) {
                maxFreq = it->second.size();
                subLen = it->second.back() - it->second[0] + 1;
            } else if (it->second.size() == maxFreq) {
                subLen = min(subLen, it->second.back() - it->second[0] + 1);
            }
        }

        return subLen;
    }
};

