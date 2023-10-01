/*Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
 
Constraints:
1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverseString(char* start, char* end) {
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char* addStrings(char* num1, char* num2) {
    int index1 = strlen(num1) - 1;
    int index2 = strlen(num2) - 1;
    int carry = 0, counter = 0;

    int maxLength = (index1 > index2 ? index1 : index2) + 3;

    char* ans = (char*)malloc(sizeof(char) * maxLength);

    while (index1 >= 0 || index2 >= 0 || carry) {
        int d1 = (index1 >= 0) ? num1[index1--] - '0' : 0;
        int d2 = (index2 >= 0) ? num2[index2--] - '0' : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        ans[counter++] = '0' + (sum % 10);
    }

    ans[counter] = '\0'; // Null-terminate the result string

    reverseString(ans, ans + counter - 1);

    return ans;
}