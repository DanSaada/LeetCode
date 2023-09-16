/*Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

Constraints:
1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> output;
        int temp = nums[0];
        int size = nums.size();
        output.push_back(temp);
        for(int i = 1; i < size; i++) {
            output.push_back(nums[i] + temp);
            temp += nums[i];
        }
        return output;
     }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5}; // Sample input

    // Call the runningSum method
    vector<int> result = solution.runningSum(nums);

    // Print the result
    cout << "Running Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
