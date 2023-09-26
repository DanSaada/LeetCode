/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.*/

#include <string.h>

void reverseString(char* start, char* end) {
    char temp;

    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void removeExtraSpaces(char* s) {
    char* src = s;
    char* dst = s;
    int prevCharWasSpace = 0;

    while (*src) {
        if (*src != ' ') {
            *dst = *src;
            dst++;
            prevCharWasSpace = 0;
        }else{
            if (!prevCharWasSpace) {
                *dst = *src;
                dst++;
                prevCharWasSpace = 1;
            }
        }
        src++;
    }

    if (prevCharWasSpace) {
         
        dst--; // Remove the trailing space if present
    }

    *dst = '\0'; // Null-terminate the cleaned string
}

char* reverseWords(char* s){
    int len = strlen(s);
    reverseString(s, s + len -1);

    //remove leading spaces
    while(*s == ' '){s++;}

    char* start = s;
    char* end = s;

    //reverse each word seperatly
    while (*end != '\0') {
        if (*end == ' ') {
            reverseString(start, end - 1);
            start = end + 1;
        }
        end++;
    }

    //reverse last word
    reverseString(start, end - 1);
    //remove trailing and middle spaces
    removeExtraSpaces(s);

    return s;
}