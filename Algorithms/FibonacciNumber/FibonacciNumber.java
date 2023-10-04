public class Solution {
    public int fib(int n) {
        if (n <= 1) {return n;}
        int x = 0, y = 1, temp = 0;

        for (int i = 2; i <= n; i++) {
            temp = x;
            x = y;
            y += temp;
        }

        return y;
    }
}