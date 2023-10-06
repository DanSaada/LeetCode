/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
Constraints:
0 <= x <= 231 - 1*/

int mySqrt(int x){
    if (x == 0 || x == 1) {return x;}
    int low = 1;
    int high = x;
    int ans;

    while (low <= high){
        int mid = low + (high - low) / 2;
        long long sqr = (long long)mid * mid;

        if (sqr <= x){
            ans = mid;
            low = mid + 1;
        }else {
            high = mid -1;
        }
    }
    return ans;
}   

//example with 16 :
//1 <= 16 --> mid = 8 --> sqr = 64 --> high = 7
//1 <= 7 --> mid = 4 --> sqr = 16 --> ans = 4 low = 5
//5 <= 7 --> mid = 6 --> sqr = 36 --> high == 5
//5 <= 5 --> mid = 5 --> sqr == 25 --> high = 4
//return ans = 4
