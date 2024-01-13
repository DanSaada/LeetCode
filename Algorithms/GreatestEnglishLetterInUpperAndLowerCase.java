class Solution {
    public String greatestLetter(String s) {
        //loop starts from "z" and decrease because we want to
        //return the GREATEST english letter, and by doing so
        //we prevent the edge cases like this one:
        //s = aArR --> greatestLetter(s) = A when it is actually R.
        for (int i = 'z'; i >= 'a'; i--) {
            String lower = Character.toString(i);
            String upper = Character.toString(i - 32);
            if (s.contains(lower) && s.contains(upper)) {
                return upper;
            }
        }

        return "";
    }
}